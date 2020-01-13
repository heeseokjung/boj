#include <cstdio>
#include <utility>
#include <vector>
#include <queue>
using namespace std;

int N, M, S, D;
int adj[500][500];
int dist[500];

void dijkstra() {
    typedef pair<int, int> ii;
    priority_queue<ii, vector<ii>, greater<ii> > pq;
    dist[S] = 0;
    pq.push(pair<int, int>(dist[S], S));
    while(!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if(d > dist[u])
            continue;
        for(int v = 0; v < N; ++v) {
            if(adj[u][v]) {
                if(dist[v] == -1 || dist[u] + adj[u][v] <= dist[v]) {
                    dist[v] = dist[u] + adj[u][v];
                    pq.push(pair<int, int>(dist[v], v));
                }
            }
        }
    }
}

void backtracking() {
    queue<int> q;
    q.push(D);
    while(!q.empty()) {
        int v = q.front();
        q.pop();
        for(int u = 0; u < N; ++u) {
            if(adj[u][v] && dist[u] + adj[u][v] == dist[v]) {
                adj[u][v] = 0;
                q.push(u);
            }
        }
    }
}

int main() {
    while(true) {
        scanf("%d %d", &N, &M);
        if(N == 0 && M == 0)
            break;
        scanf("%d %d", &S, &D);
        int x, y, z;
        for(int i = 0; i < M; ++i) {
            scanf("%d %d %d", &x, &y, &z);
            adj[x][y] = z;
        }
        for(int i = 0; i < N; ++i)
            dist[i] = -1;
        dijkstra();
        if(dist[D] == -1) {
            printf("-1\n");
        }
        else {
            backtracking();
            for(int i = 0; i < N; ++i)
                dist[i] = -1;
            dijkstra();
            printf("%d\n", dist[D]);
        }
        for(int i = 0; i < N; ++i)
            for(int j = 0; j < N; ++j)
                adj[i][j] = 0;
    }
    return 0;
}