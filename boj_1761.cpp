#include <cstdio>
#include <utility>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, M;
int dist[40001];
int depth[40001];
int parent[40001][17];
bool visit[40001];
vector<pair<int, int> > adj[40001];

void dfs(int x, int _dist, int _depth) {
    visit[x] = true;
    dist[x] = _dist;
    depth[x] = _depth;
    for(int i = 0; i < (int)adj[x].size(); ++i) {
        if(!visit[adj[x][i].first]) {
            parent[adj[x][i].first][0] = x;
            dfs(adj[x][i].first, _dist + adj[x][i].second, _depth + 1);
        }
    }
}

int lca(int x, int y) {
    if(depth[x] > depth[y])
        swap(x, y);
    for(int i = 16; i >= 0; --i) {
        if(depth[y] - depth[x] >= (1 << i))
            y = parent[y][i];
    }
    if(x == y)
        return x;
    for(int i = 16; i >= 0; --i) {
        if(parent[x][i] != parent[y][i]) {
            x = parent[x][i];
            y = parent[y][i];
        }
    }
    return parent[x][0];
}

int main() {
    scanf("%d", &N);
    int x, y, z;
    for(int i = 0; i < N-1; ++i) {
        scanf("%d %d %d", &x, &y, &z);
        adj[x].push_back(pair<int, int>(y, z));
        adj[y].push_back(pair<int, int>(x, z));
    }

    dfs(1, 0, 0);
    for(int j = 1; j < 17; ++j) {
        for(int i = 1; i <= N; ++i) {
            parent[i][j] = parent[parent[i][j-1]][j-1];
        }
    }

    scanf("%d", &M);
    for(int i = 0; i < M; ++i) {
        scanf("%d %d", &x, &y);
        int p = lca(x, y);
        if(p == x)
            printf("%d\n", dist[y] - dist[x]);
        else if(p == y)
            printf("%d\n", dist[x] - dist[y]);
        else
            printf("%d\n", (dist[x]-dist[p]) + (dist[y]-dist[p]));
    }
    return 0;
}