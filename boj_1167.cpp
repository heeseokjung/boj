#include <stdio.h>
#include <utility>
#include <vector>
#include <queue>
using namespace std;

int V;
vector<pair<int, int> > adj[100001];
bool visit[100001] = {false, };
int indegree[100001] = {0, };
int dist[100001];
int m_dist[100001];

void input()
{
    scanf("%d", &V);
    int u, v, w;
    for(int i = 1; i <= V; ++i) {
        scanf("%d", &u);
        while(true) {
            scanf("%d", &v);
            if(v == -1)
                break;
            indegree[v]++;
            scanf("%d", &w);
            adj[u].push_back(make_pair(v, w));
        }
    }
}

void bfs(int x)
{
    queue<pair<int, int> > q;
    dist[x] = 0; visit[x] = true;
    q.push(make_pair(x, dist[x]));
    int u, w;
    while(!q.empty()) {
        u = q.front().first;
        w = q.front().second;
        q.pop();
        dist[u] = w;
        for(int i = 0; i < (int)adj[u].size(); ++i) {
            if(!visit[adj[u][i].first]) {
                visit[adj[u][i].first] = true;
                q.push(make_pair(adj[u][i].first, w + adj[u][i].second));
            }
        }
    }
    
}

void run()
{
    bfs(1);
    int max = -1, max_node;
    for(int i = 1; i <= V; ++i) {
        if(dist[i] > max) {
            max = dist[i];
            max_node = i;
        }
    }

    for(int i = 1; i <= V; ++i) {
        m_dist[i] = dist[i];
        visit[i] = false;
    }

    bfs(max_node);
    max = -1;
    for(int i = 1; i <= V; ++i) {
        if(dist[i] > max) {
            max = dist[i];
            max_node = i;
        }
    }

    printf("%d\n", dist[max_node]);
}

int main()
{
    input();
    run();
    return 0;
}