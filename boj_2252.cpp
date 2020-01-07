#include <cstdio>
#include <vector>
#include <stack>
using namespace std;

int N, M;
bool visit[32001];
vector<int> adj[32001];
stack<int> s;

void dfs(int u) {
    visit[u] = true;
    for(int i = 0; i < (int)adj[u].size(); ++i) {
        int v = adj[u][i];
        if(!visit[v])
            dfs(v);
    }
    s.push(u);
}

int main() {
    scanf("%d %d", &N, &M);
    int x, y;
    for(int i = 0; i < M; ++i) {
        scanf("%d %d", &x, &y);
        adj[x].push_back(y);
    }
    for(int i = 1; i <= N; ++i) {
        if(!visit[i])
            dfs(i);
    }
    while(!s.empty()) {
        printf("%d ", s.top());
        s.pop();
    }
    printf("\n");
    return 0;
}