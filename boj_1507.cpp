#include <stdio.h>

int n;
int dist[21][21];
int adj[21][21];

void input()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            scanf("%d", &dist[i][j]);
        }
    }
}

void run()
{
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            adj[i][j] = 1;
        }
    }

    for(int k = 1; k <= n; ++k) {
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= n; ++j) {
                if(k != i && k != j && dist[i][j] == dist[i][k] + dist[k][j]) {
                    adj[i][j] = 0;
                }
                else if(k != i && k != j && dist[i][j] > dist[i][k] + dist[k][j]) {
                    printf("-1\n");
                    return;
                }
            }
        }
    }

    int ans = 0;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            if(adj[i][j])
                ans += dist[i][j];
        }
    }
    printf("%d\n", ans / 2);
}

int main()
{
    input();
    run();
    return 0;
}