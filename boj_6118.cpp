#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int N, M;
vector<int> adj[20001];
int dist[20001];

int main() {
    scanf("%d %d", &N, &M);
    for(int i = 0; i < M; ++i) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i = 1; i <= N; ++i)
        dist[i] = -1;

    dist[1] = 0;
    queue<int> q;
    q.push(1);
    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(int i = 0; i < (int)adj[u].size(); ++i) {
            int v = adj[u][i];
            if(dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    int mx = -1, idx = 2;
    for(int i = 2; i <= N; ++i) {
        if(mx < dist[i]) {
            mx = dist[i];
            idx = i;
        }
    }
    int dup = 0;
    for(int i = 2; i <= N; ++i) {
        if(dist[idx] == dist[i])
            dup++;
    }

    printf("%d %d %d\n", idx, dist[idx], dup);

    return 0;
}