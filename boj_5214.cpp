#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int N, K, M;
bool visit[101010];
int dist[100001];
vector<int> adj[101010];

int main() {
    scanf("%d %d %d", &N, &K, &M);
    for(int i = N+1; i <= N+M; ++i) {
        int x;
        for(int j = 0; j < K; ++j) {
            scanf("%d", &x);
            adj[x].push_back(i);
            adj[i].push_back(x);
        }
    }
    queue<int> q;
    visit[1] = true; dist[1] = 0;
    q.push(1);
    while(!q.empty()) {
        int u = q.front(); q.pop();
        if(u == N)
            break;
        int size = (int)adj[u].size();
        for(int i = 0; i < size; ++i) {
            //printf("size: %d i: %d\n",size,  i);
            int v = adj[u][i];
            if(!visit[v]) {
                visit[v] = true;
                dist[v] = dist[u] + ((v > N) ? 0 : 1);
                q.push(v);
            }
        }
    }
    printf("%d\n", visit[N] ? dist[N] + 1 : -1);
    for(int i = 1; i <= N; ++i)
        printf("size[%d]: %d\n", i, (int)adj[i].size());
    return 0;
}