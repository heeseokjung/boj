// boj_11404

#include <cstdio>

using namespace std;

#define INF 1000000000

int n, m;
int adj[101][101];

void run()
{
    for(int k = 1; k <= n; ++k) {
        for(int i = 1; i <= n; ++i) {
            if(i == k)
                continue;
            for(int j = 1; j <= n; ++j) {
                if(j == k)
                    continue;
                if(adj[i][k] + adj[k][j] < adj[i][j] && 
                   adj[i][k] != INF && adj[k][j] != INF)
                    adj[i][j] = adj[i][k] + adj[k][j];
            }
        }
    }

    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            if(adj[i][j] == INF)
                printf("%d ", 0);
            else
                printf("%d ", adj[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            if(i == j)
                adj[i][j] = 0;
            else
                adj[i][j] = INF;
        }
    }
    int u, v, w;
    for(int i = 0; i < m; ++i) {
        scanf("%d %d %d", &u, &v, &w);
        if(adj[u][v] > w)
            adj[u][v] = w;
    }
    
    run();

    return 0;
}