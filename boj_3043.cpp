#include <cstdio>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<pair<pair<int, int>, int> > v;
vector<pair<int, char> > ans;

inline bool cmp(pair<pair<int, int>, int>& p1, pair<pair<int, int>, int>& p2) {
    if(p1.first.first < p2.first.first)
        return true;
    else if(p1.first.first == p2.first.first)
        return p1.first.second < p2.first.second;
    else
        return false;
}

inline void swap(int& x, int& y) {
    int tmp = x;
    x = y;
    y = tmp;
}

void run(char c1, char c2) {
    vector<int> s1, s2;
    for(int i = 0; i < N; ++i) {
        if(v[i].first.first > i+1)
            s1.push_back(i);
        else if(v[i].first.first < i+1)
            s2.push_back(i);
    }
    for(int i = 0; i < (int)s1.size(); ++i) {
        int idx = s1[i];
        for(int j = v[idx].first.first; j > idx+1; --j) {
            ans.push_back(pair<int, char>(v[idx].second, c1));
        }
    }
    for(int i = (int)s2.size()-1; i >= 0; --i) {
        int idx = s2[i];
        for(int j = v[idx].first.first; j < idx+1; ++j) {
            ans.push_back(pair<int, char>(v[idx].second, c2));
        }
    }
}

int main() {
    scanf("%d", &N);
    v = vector<pair<pair<int, int>, int> >(N);
    for(int i = 0; i < N; ++i) {
        scanf("%d %d", &v[i].first.first, &v[i].first.second);
        v[i].second = i+1;
    }

    sort(v.begin(), v.end(), cmp);
    run('U', 'D');

    for(int i = 0; i < N; ++i)
        swap(v[i].first.first, v[i].first.second);
    sort(v.begin(), v.end(), cmp);
    run('L', 'R');

    printf("%d\n", (int)ans.size());
    for(int i = 0; i < (int)ans.size(); ++i)
        printf("%d %c\n", ans[i].first, ans[i].second);
    return 0;
}