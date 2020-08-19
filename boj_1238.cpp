#include <cstdio>
#include <utility>
#include <vector>
#include <queue>
using namespace std;

int N, M, X;
int dist[1001][1001];
const int inf = (int)1e9;
vector<pair<int, int> > adj[10001];

void shortest_path(int src) {
    for(int i = 1; i <= N; ++i)
        dist[src][i] = inf;

    priority_queue<pair<int, int> > pq;
    dist[src][src] = 0;
    pq.push({0, src});

    while(!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if(dist[src][u] < d)
            continue;

        int size = (int)adj[u].size();
        for(int i = 0; i < size; ++i) {
            int v = adj[u][i].first;
            int w = adj[u][i].second;
            if(dist[src][u] + w < dist[src][v]) {
                dist[src][v] = dist[src][u] + w;
                pq.push({dist[src][u] + w, v});
            }
        }
    }
}

int main() {
    scanf("%d %d %d", &N, &M, &X);
    for(int i = 0; i < M; ++i) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        adj[u].push_back({v, w});
    }

    for(int i = 1; i <= N; ++i)
        shortest_path(i);

    int max_dist = -1;
    for(int i = 1; i <= N; ++i) {
        if(dist[i][X] + dist[X][i] > max_dist)
            max_dist = dist[i][X] + dist[X][i];
    }

    printf("%d\n", max_dist);

    return 0;
}