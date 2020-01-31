#include <cstdio>
#define MOD 1000000003

int N, K;
int dp[10001][1001];

int main() {
    scanf("%d %d", &N, &K);
    for(int i = 1; i <= N; ++i) {
        dp[i][0] = 1;
        dp[i][1] = i;
    }
    for(int i = 2; i <= N; ++i) {
        for(int j = 2; j <= K; ++j) {
            dp[i][j] = (dp[i-2][j-1]%MOD + dp[i-1][j]%MOD)%MOD;
        }
    }
    printf("%d\n", (dp[N-3][K-1] + dp[N-1][K])%MOD);
    return 0;
}