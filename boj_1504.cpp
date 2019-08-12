#include <stdio.h>
#include <utility>
#include <vector>
#include <queue>
using namespace std;

int N, E, S, P;
vector<pair<int, int> > adj[801];
vector<int> root;
int dist[3][801];
#define INF 1000000000

void input()
{
    scanf("%d %d", &N, &E);
    int u, v, w;
    for(int i = 0; i < E; ++i) {
        scanf("%d %d %d", &u, &v, &w);
        adj[u].push_back(pair<int, int>(v, w));
        adj[v].push_back(pair<int, int>(u, w));
    }
    scanf("%d %d", &S, &P);
    root.push_back(1);
    root.push_back(S);
    root.push_back(P);
}

void dijkstra(int x, int idx)
{
    typedef pair<int, int> ii;
    priority_queue<ii, vector<ii>, greater<ii> > pq;
    dist[idx][x] = 0;
    pq.push(ii(dist[idx][x], x));

    while(!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if(d > dist[idx][u])
            continue;
        for(int i = 0; i < (int)adj[u].size(); ++i) {
            if(d + adj[u][i].second < dist[idx][adj[u][i].first]) {
                dist[idx][adj[u][i].first] = d + adj[u][i].second;
                pq.push(ii(dist[idx][adj[u][i].first], adj[u][i].first));
            }
        }
    }
}

void run()
{
    for(int i = 0; i < 3; ++i) {
        for(int j = 1; j <= N; ++j) {
            dist[i][j] = INF;
        }
    }

    for(int i = 0; i < 3; ++i)
        dijkstra(root[i], i);

    int p1, p2;
    if(dist[0][S] == INF || dist[1][P] == INF || dist[2][N] == INF)
        p1 = INF;
    else
        p1 = dist[0][S] + dist[1][P] + dist[2][N];
    if(dist[0][P] == INF || dist[2][S] == INF || dist[1][N] == INF)
        p2 = INF;
    else
        p2 = dist[0][P] + dist[2][S] + dist[1][N];
    if(p1 == INF && p2 == INF)
        printf("%d\n", -1);
    else
        printf("%d\n", p1 < p2 ? p1 : p2);
}

int main()
{
    input();
    run();
}