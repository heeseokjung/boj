#include <cstdio>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
typedef pair<int, int> ii;
vector<pair<int, ii> > edge;
int parent[100001];
long long size[100001];
#define MOD 1000000000

inline bool comp(pair<int, ii>& p1, pair<int, ii>& p2) {
    return p1.first > p2.first;
}

int Find(int v) {
    int u = v;
    while(parent[u] > 0)
        u = parent[u];
    if(parent[v] > 0)
        parent[v] = u;
    return u;
}

void Union(int v1, int v2) {
    int r1 = Find(v1);
    int r2 = Find(v2);
    if(r1 == r2)
        return;
    if(parent[r1] < parent[r2]) {
        parent[r2] = r1;
        size[r1] += size[r2];
        size[r2] = 1;
    }
    else if(parent[r1] > parent[r2]) {
        parent[r1] = r2;
        size[r2] += size[r1];
        size[r1] = 1;
    }
    else {
        parent[r2] = r1;
        parent[r1]--;
        size[r1] += size[r2];
        size[r2] = 1;
    }
}

int main() {
    scanf("%d %d", &N, &M);
    int u, v, w;
    long long total = 0;
    for(int i = 0; i < M; ++i) {
        scanf("%d %d %d", &u, &v, &w);
        edge.push_back(make_pair(w, pair<int, int>(u, v)));
        total += (long long)w;
    }
    for(int i = 1; i <= N; ++i)
        size[i] = 1;
    sort(edge.begin(), edge.end(), comp);
    long long sum = 0, ans = 0;
    for(int i = 0; i < M; ++i) {
        int w = edge[i].first;
        int u = edge[i].second.first;
        int v = edge[i].second.second;
        int r1 = Find(u);
        int r2 = Find(v);
        if(r1 != r2) {
            ans += ((size[r1]*size[r2])%MOD*(total - sum)%MOD)%MOD;
            ans %= MOD;
            Union(u, v);
        }
        sum += w;
    }
    printf("%lld\n", ans);
    return 0;
}