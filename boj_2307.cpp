#include <cstdio>
#include <cstdlib>
#include <utility>
#include <vector>
#include <queue>
using namespace std;

int N, M;
vector<pair<int, int> > adj[1001];
int dist[1001];
int parent[1001];
vector<pair<int, int> > path;
#define INF 1e9

int dijkstra() {
    for(int i = 1; i <= N; ++i)
        dist[i] = (int)1e9;
    typedef pair<int, int> ii;
    priority_queue<ii, vector<ii>, greater<ii> > pq;
    dist[1] = 0;
    pq.push(pair<int, int>(0, 1));
    while(!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        int size = (int)adj[u].size();
        for(int i = 0; i < size; ++i) {
            int v = adj[u][i].first;
            int w = adj[u][i].second;
            if(dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                parent[v] = u;
                pq.push(pair<int, int>(dist[v], v));
            }
        }
    }
    return dist[N];
}

void make_path() {
    int x = N;
    while(parent[x]) {
        path.push_back(pair<int, int>(parent[x], x));
        x = parent[x];
    }
}

int main() {
    scanf("%d %d", &N, &M);
    int a, b, t;
    for(int i = 0; i < M; ++i) {
        scanf("%d %d %d", &a, &b, &t);
        adj[a].push_back(pair<int, int>(b, t));
        adj[b].push_back(pair<int, int>(a, t));
    }
    int mincost = dijkstra();
    if(dist[N] == INF) {
        printf("-1\n");
    } else {
        make_path();
        int delay = 0;
        int size = (int)path.size();
        for(int i = 0; i < size; ++i) {
            int u = path[i].first;
            int v = path[i].second;
            for(int j = 0; j < (int)adj[u].size(); ++j) {
                if(adj[u][j].first == v) {
                    int w = adj[u][j].second;
                    adj[u][j].second = (int)INF;
                    int newcost = dijkstra();
                    if(newcost >= INF) {
                        printf("-1\n");
                        exit(0);
                    }
                    if(newcost - mincost > delay)
                        delay = newcost - mincost;
                    adj[u][j].second = w;
                    break;
                }
            }
        }
        printf("%d\n", delay);
    }
    return 0;
}