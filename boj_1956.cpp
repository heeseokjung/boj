#include <cstdio>

int V, E;
int adj[401][401];
int d[401][401];
const int inf = (int)1e9;

int main() {
    scanf("%d %d", &V, &E);
    for(int i = 0; i < E; ++i) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        adj[u][v] = w;
    }

    for(int i = 1; i <= V; ++i) {
        for(int j = 1; j <= V; ++j) {
            if(i == j)
                d[i][j] = 0;
            else if(adj[i][j])
                d[i][j] = adj[i][j];
            else
                d[i][j] = inf;
        }
    }

    for(int k = 1; k <= V; ++k) {
        for(int i = 1; i <= V; ++i) {
            for(int j = 1; j <= V; ++j) {
                if(d[i][j] > d[i][k] + d[k][i])
                    d[i][j] = d[i][k] + d[k][j];
            }
        }
    }

    int ans = inf;
    for(int i = 1; i <= V; ++i) {
        for(int j = 1; j <= V; ++j) {
            if(i != j && d[i][j] + d[j][i] < ans)
                ans = d[i][j] + d[j][i];
        }
    }

    printf("%d\n", ans == inf ? -1 : ans);

    return 0;
}