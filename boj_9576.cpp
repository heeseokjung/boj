#include <cstdio>
#include <vector>
using namespace std;

int N, M;
vector<int> adj[2001];
vector<int> match;

bool dfs(vector<bool>& visit, int u) {
    if(visit[u])
        return false;
    visit[u] = true;
    for(int v : adj[u]) {
        if(match[v] == -1 || dfs(visit, match[v])) {
            match[u] = v;
            match[v] = u;
            return true;
        }
    }
    return false;
}

int main() {
    int TC;
    scanf("%d", &TC);
    while(TC--) {
        scanf("%d %d", &N, &M);
        int s, e;
        for(int i = 0; i < M; ++i) {
            scanf("%d %d", &s, &e);
            for(int j = s; j <= e; ++j)
                adj[i+1].push_back(j+M);
        }

        int count = 0;
        match = vector<int>(M+N+1, -1);
        for(int i = 1; i <= M; ++i) {
            vector<bool> visit(N+1, false);
            if(dfs(visit, i))
                count++;
        }

        for(int i = 0; i < 2001; ++i)
            adj[i].clear();
        match.clear();

        printf("%d\n", count);
    }
    return 0;
}