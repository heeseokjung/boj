#include <stdio.h>

int main() {
    int TC;
    int N, L, R;
    long long dp[21][21][21];
    for(int i = 0; i < 21; ++i)
        for(int j = 0; j < 21; ++j)
            for(int k = 0; k < 21; ++k)
                dp[i][j][k] = 0;
    dp[1][1][1] = 1;
    for(int i = 2; i <= 20; ++i) {
        for(int j = 1; j <= i; ++j) {
            for(int k = 1; k <= i; ++k) {
                dp[i][j][k] = dp[i-1][j-1][k] + dp[i-1][j][k-1] + (i-2)*dp[i-1][j][k];
            }
        }
    }
    scanf("%d", &TC);
    while(TC--) {
        scanf("%d %d %d", &N, &L, &R);
        printf("%lld\n", dp[N][L][R]);
    }
    return 0;
}