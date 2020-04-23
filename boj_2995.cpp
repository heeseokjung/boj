#include <cstdio>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<pair<int, int> > v;
int tree[3000000];
int dp[100000];
int next_pos[100000];

inline bool cmp(pair<int, int>& p1, pair<int, int>& p2) {
    if(p1.first != p2.first)
        return p1.first > p2.first;
    else
        return p1.second < p2.second;
}

void init_tree(int i, int j, int n)
{
    tree[n] = -1;
    if(i == j)
        return;
    init_tree(i, (i+j)/2, n*2);
    init_tree((i+j)/2 + 1, j, n*2 + 1);
}

int query(int i, int j, int l, int r, int n)
{
    if(i > r || j < l)
        return -1;
    if(l <= i && j <= r)
        return tree[n];
    int lmax = query(i, (i+j)/2, l, r, n*2);
    int rmax = query((i+j)/2 + 1, j, l, r, n*2 + 1);
    if(lmax == -1 && rmax == -1)
        return -1;
    if(lmax == -1 && rmax != -1)
        return rmax;
    if(lmax != -1 && rmax == -1)
        return lmax;
    if(lmax != -1 && rmax != -1)
        return (dp[lmax] < dp[rmax]) ? rmax : lmax;
}

int update(int i, int j, int n, int idx, int val)
{
    if(idx < i || idx > j)
        return tree[n];
    if(i == j)    
        return tree[n] = val;
    int lmax = update(i, (i+j)/2, n*2, idx, val);
    int rmax = update((i+j)/2 + 1, j, n*2 + 1, idx, val);
    if(lmax == -1 && rmax == -1)
        return tree[n] = -1;
    if(lmax == -1 && rmax != -1)
        return tree[n] = rmax;
    if(lmax != -1 && rmax == -1)
        return tree[n] = lmax;
    if(lmax != -1 && rmax != -1)
        return tree[n] = (dp[lmax] < dp[rmax] ? rmax : lmax);
}

int main() {
    scanf("%d", &N);
    v = vector<pair<int, int> >(N);
    int bound = 1;
    for(int i = 0; i < N; ++i) {
        scanf("%d %d", &v[i].first, &v[i].second);
        bound = (bound < v[i].second ? v[i].second : bound);
    }

    sort(v.begin(), v.end(), cmp);
    init_tree(0, bound, 1);

    int mx = 0;
    for(int i = 0; i < N; ++i) {
        dp[i] = 1;
        next_pos[i] = -1;
        int j = query(0, bound, 0, v[i].second, 1);
        if(j != -1) {
            dp[i] = dp[j] + 1;
            next_pos[i] = j;
        }
        update(0, bound, 1, v[i].second, i);
        if(dp[i] > dp[mx])
            mx = i;
    }

    printf("%d\n", dp[mx]);
    while(mx != -1) {
        printf("%d %d\n", v[mx].first, v[mx].second);
        mx = next_pos[mx];
    }
    
    return 0;
}