#include <cstdio>
#include <utility>
#include <vector>
#include <queue>
using namespace std;

int N, M, X;
int dist[1001];
int dist_prime[1001];
const int inf = (int)1e9;
vector<pair<int, int> > adj[1001];
vector<pair<int, int> > adj_copy[1001];

void shortest_path(int src, int* dist) {
    for(int i = 1; i <= N; ++i)
        dist[i] = inf;

    priority_queue<pair<int, int> > pq;
    dist[src] = 0;
    pq.push({0, src});

    while(!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if(dist[u] < d)
            continue;

        int size = (int)adj[u].size();
        for(int i = 0; i < size; ++i) {
            int v = adj[u][i].first;
            int w = adj[u][i].second;
            if(dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[u] + w, v});
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

    shortest_path(X, dist);

    for(int i = 1; i <= N; ++i) {
        adj_copy[i] = adj[i];
        adj[i].clear();
    }
    for(int i = 1; i <= N; ++i) {
        for(int j = 0; j < (int)adj_copy[i].size(); ++j) {
            int u = i;
            int v = adj_copy[i][j].first;
            int w = adj_copy[i][j].second;
            adj[v].push_back({u, w});
        }
    }

    shortest_path(X, dist_prime);

    int max_dist = -1;
    for(int i = 1; i <= N; ++i) {
        if(dist[i] + dist_prime[i] > max_dist)
            max_dist = dist[i] + dist_prime[i];
    }

    printf("%d\n", max_dist);

    return 0;
}