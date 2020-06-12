#include <cstdio>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

inline bool cmp(pair<pair<int, int>, int>& p1, pair<pair<int, int>, int>& p2) {
    if(p1.first.second != p2.first.second)
        return p1.first.second < p2.first.second;
    else
        return p1.first.first < p2.first.first;
}

int main() {
    int N, C, M;
    scanf("%d %d %d", &N, &C, &M);
    vector<pair<pair<int, int>, int> > v(N);
    for(int i = 0; i < M; ++i)
        scanf("%d %d %d", &v[i].first.first, &v[i].first.second, &v[i].second);

    sort(v.begin(), v.end(), cmp);

    int sum = 0;
    vector<int> capacity(N+1, 0);
    for(int i = 0; i < M; ++i) {
        int src = v[i].first.first;
        int dest = v[i].first.second;
        int weight = v[i].second;
    }    

    return 0;
}