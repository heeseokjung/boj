#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

int TC;
int M, N, L, G;
int adj[101][101][2];
int dp[101][101][201][2];

void run()
{
    scanf("%d", &TC);
    while(TC--) {
        scanf("%d %d %d %d", &M, &N, &L, &G);
        for(int i = 1; i <= M; ++i) {
            for(int j = 1; j < N; ++j) {
                scanf("%d", &adj[i][j][0]);
            }
        }
        for(int i = 1; i < M; ++i) {
            for(int j = 1; j <= N; ++j) {
                scanf("%d", &adj[i][j][1]);
            }
        }
        for(int i = 1; i <= M; ++i) {
            for(int j = 1; j <= N; ++j) {
                for(int k = 0; k <= N + M; ++k)
                    dp[i][j][k][0] = dp[i][j][k][1] = G + 1;
            }
        }

        dp[1][1][0][0] = dp[1][1][0][1] = 0;
        for(int i = 1; i <= M; ++i) {
            for(int j = 1; j <= N; ++j) {
                for(int k = 0; k <= M + N; ++k) {
                    if(i != 1) {
                        dp[i][j][k][1] = dp[i-1][j][k][1] + adj[i-1][j][1];
                        if(k != 0)
                            dp[i][j][k][1] = min(dp[i][j][k][1], dp[i-1][j][k-1][0] + adj[i-1][j][1]);
                    }
                    if(j != 1) {
                        dp[i][j][k][0] = dp[i][j-1][k][0] + adj[i][j-1][0];
                        if(k != 0)
                            dp[i][j][k][0] = min(dp[i][j][k][0], dp[i][j-1][k-1][1] + adj[i][j-1][0]);
                    }
                }
            }
        }

        int ans = -1;
        for(int k = 0; k <= N + M; ++k) {
            if(dp[M][N][k][0] <= G || dp[M][N][k][1] <= G) {
                if(ans < 0 || ans > (N - 1 + M - 1)*L + k)
                    ans = (N - 1 + M - 1)*L + k;
            }
        }
        printf("%d\n", ans);
    }
}

int main()
{
    run();
    return 0;
}