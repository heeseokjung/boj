#include <cstdio>

int N, C;
long long dp[1001][10001];
long long rsum[10001];
#define mod 1000000007

int main() {
    int N, C;
    scanf("%d %d", &N, &C);
    dp[1][0] = 1LL;
    for(int i = 2; i <= N; ++i) {
        for(int j = 0; j <= C; ++j) {
            if(j == 0)
                rsum[j] = dp[i-1][j];
            else
                rsum[j] = (rsum[j-1] + dp[i-1][j])%mod;
        }
        for(int j = 0; j <= C; ++j) {
            dp[i][j] = rsum[j];
            if(j > i-1)
                dp[i][j] = (dp[i][j] - rsum[j-i] + mod)%mod;
        }
    }
    printf("%lld\n", dp[N][C]);
    return 0;
}