// boj_1753

#include <cstdio>
#include <string.h>
#include <utility>
#include <vector>
#include <queue>

using namespace std;

#define INF 1000000000

int num_v, num_e;
int dist[20001];
typedef pair<int, int> p;
vector<p> adj[20001];

void run(int src)
{
    priority_queue<p, vector<p>, greater<p> > pq;
    dist[src] = 0;
    pq.push(make_pair(dist[src], src));
    while(!pq.empty()) {
        pair<int, int> tmp = pq.top(); pq.pop();
        int w = tmp.first;
        int u = tmp.second;
        if(dist[u] < w)
            continue;
        for(int i = 0; i < adj[u].size(); ++i) {
            int v = adj[u][i].first;
            int w = adj[u][i].second;
            if(dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push(make_pair(dist[v], v));
            }
        }
    }

    for(int i = 1; i <= num_v; ++i) {
        if(dist[i] == INF)
            printf("INF\n");
        else
            printf("%d\n", dist[i]);
    }
}

int main()
{
    scanf("%d %d", &num_v, &num_e);
    int src;
    scanf("%d", &src);
    for(int i = 0; i < num_e; ++i) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        adj[u].push_back(make_pair(v, w));
    }
    for(int i = 1; i <= num_v; ++i)
        dist[i] = INF;
   
    run(src);

    return 0;
}