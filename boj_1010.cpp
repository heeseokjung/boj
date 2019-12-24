#include <cstdio>

int main() {
    int TC;
    scanf("%d", &TC);
    int N, M;
    long long dp[30][30];
    while(TC--) {
        scanf("%d %d", &N, &M);
        for(int i = 0; i < N; ++i)
            for(int j = 0; j < M; ++j)
                dp[i][j] = 0;
        for(int i = 0; i < M; ++i)
            dp[0][i] = i+1;
        for(int i = 1; i < N; ++i) {
            for(int j = 0; j < M; ++j) {
                for(int k = 0; k < j; ++k) {
                    dp[i][j] += dp[i-1][k];
                }
            }
        }
        printf("%lld\n", dp[N-1][M-1]);
    }
    return 0;
}