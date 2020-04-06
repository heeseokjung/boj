#include <cstdio>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<pair<int, int> > v;
vector<int> x[100001];
vector<int> y[100001];

int main() {
    scanf("%d", &N);
    v = vector<pair<int, int> >(N);
    for(int i = 0; i < N; ++i) {
        scanf("%d %d", &v[i].first, &v[i].second);
        x[v[i].first].push_back(v[i].second);
        y[v[i].second].push_back(v[i].first);
    }

    for(int i = 1; i <= 100000; ++i) {
        if(!x[i].empty())
            sort(x[i].begin(), x[i].end());
        if(!y[i].empty())
            sort(y[i].begin(), y[i].end());
    }

    long long count = 0;
    for(int i = 0; i < N; ++i) {
        pair<int, int> p = v[i];
        vector<int>::iterator ity = find(x[p.first].begin(), x[p.first].end(), p.second);
        vector<int>::iterator itx = find(y[p.second].begin(), y[p.second].end(), p.first);
        long long by = (long long)(x[p.first].end() - ity - 1);
        long long sy = (long long)(ity - x[p.first].begin());
        long long bx = (long long)(y[p.second].end() - itx - 1);
        long long sx = (long long)(itx - y[p.second].begin());
        count += by * bx;
        count += by * sx;
        count += sx * sy;
        count += sy * bx;
    }
    printf("%lld\n", count);

    return 0;
}