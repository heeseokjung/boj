#include <cstdio>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<pair<int, int> > v;

inline bool cmp(pair<int, int>& p1, pair<int, int>& p2) {
    if(p1.first != p2.first)
        return p1.first > p2.first;
    else
        return p1.second < p2.second;
}

int main() {
    scanf("%d", &N);
    v = vector<pair<int, int> >(N);
    for(int i = 0; i < N; ++i)
        scanf("%d %d", &v[i].first, &v[i].second);

    sort(v.begin(), v.end(), cmp);

    
    
    return 0;
}