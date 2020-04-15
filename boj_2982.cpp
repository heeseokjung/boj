#include <cstdio>
#include <utility>
#include <vector>
#include <queue>
using namespace std;

int N, M;
int A, B, K, G;
vector<int> path;
int adj[1001][1001];
bool ban[1001][1001];
int arrive[1001];
int dist[1001];
#define INF (int)1e9

void run() {
    for(int i = 1; i <= N; ++i)
        dist[i] = INF;

    typedef pair<int, int> ii;
    priority_queue<ii, vector<ii>, greater<ii> > pq;

    dist[A] = K;
    pq.push(pair<int, int>(K, A));
    while(!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();
        if(d > dist[u])
            continue;
        for(int v = 1; v <= N; ++v) {
            if(u == v || adj[u][v] == 0)
                continue;
            int est = d + adj[u][v];
            printf("u: %d v: %d d: %d arrive[u]: %d adj[u][v]: %d\n", u, v, d, arrive[u], adj[u][v]);
            if(ban[u][v] && d >= arrive[u] && d < arrive[u] + adj[u][v]) {
                est += arrive[u] + adj[u][v] - d;
            }
            if(dist[v] > est) {
                dist[v] = est;
                pq.push(pair<int, int>(dist[v], v));
            }
        }
    }
}

int main() {
    scanf("%d %d", &N, &M);
    scanf("%d %d %d %d", &A, &B, &K, &G);
    path = vector<int>(G);
    for(int i = 0; i < G; ++i)
        scanf("%d", &path[i]);
    for(int i = 0; i < M; ++i) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        adj[u][v] = w;
        adj[v][u] = w;
    }

    for(int i = 0, j = 0; i < G; ++i) {
        int u = path[i];
        arrive[u] = j;
        if(i < G-1) {
            int v = path[i+1];
            ban[u][v] = true;
            j += adj[u][v];
        }
    }

    run();

    printf("%d\n", dist[B] - K);

    for(int i = 1; i <= N; ++i)
        printf("dist[%d]: %d arrive[%d]: %d\n", i, dist[i], i, arrive[i]);

    return 0;
}