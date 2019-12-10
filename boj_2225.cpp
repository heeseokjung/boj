#include <cstdio>

int N, K;
long long dp[201][201];

int main() {
    scanf("%d %d", &N, &K);
    for(int i = 0; i <= N; ++i)
        dp[i][1] = 1;
    for(int i = 0; i <= N; ++i) {
        for(int j = 1; j <= K; ++j) {
            for(int k = 0; k <= i; ++k)
                dp[i][j] = (dp[i][j] + dp[i-k][j-1]) % 1000000000;
        }
    }
    printf("%lld\n", dp[N][K]);
    return 0;
}