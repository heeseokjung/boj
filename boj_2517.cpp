#include <cstdio>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int tree[2000000];
int ans[500000];
vector<pair<int, int> > v;

inline bool compare(pair<int, int>& p1, pair<int, int>& p2) {
    return p1.second < p2.second;
}

int query(int i, int j, int p, int q, int n) {
    if(i > q || j < p)
        return 0;
    if(i >= p && j <= q)
        return tree[n];
    return query(i, (i+j)/2, p, q, n*2) + query((i+j)/2 + 1, j, p, q, n*2 + 1);
}

void update(int i, int j, int pos, int val, int n) {
    if(pos < i || pos > j)
        return;
    tree[n] += val;
    if(i != j) {
        update(i, (i+j)/2, pos, val, n*2);
        update((i+j)/2 + 1, j, pos, val, n*2 + 1);
    }
}

int main() {
    scanf("%d", &N);
    int x;
    v.reserve(N);
    for(int i = 0; i < N; ++i) {
        scanf("%d", &x);
        v.push_back(pair<int, int>(i, x));
    }
    sort(v.begin(), v.end(), compare);
    for(int i = 0; i < N; ++i) {
        int pos = v[i].first;
        ans[pos] = (pos > 0) ? pos - query(0, N-1, 0, pos-1, 1) + 1 : 1;
        update(0, N-1, pos, 1, 1);
    }
    for(int i = 0; i < N; ++i)
        printf("%d\n", ans[i]);
    return 0;
}