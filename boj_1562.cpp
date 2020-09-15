#include <cstdio>

int N;
int dp[101][10];
const int mod = (int)1e9;

int main() {
    scanf("%d", &N);
    for(int j = 0; j < 10; ++j)
        dp[1][j] = 1;
    for(int j = 1; j < 10; ++j) {
        if(j-1 >= 0) {
            dp[2][j-1] += dp[1][j];
            dp[2][j-1] %= mod;
        }
        if(j+1 < 10) {
            dp[2][j+1] += dp[1][j];
            dp[2][j+1] %= mod;
        }
    }
    for(int i = 2; i < N; ++i) {
        for(int j = 0; j < 10; ++j) {
            if(j-1 >= 0) {
                dp[i+1][j-1] += dp[i][j];
                dp[i+1][j-1] %= mod;
            }
            if(j+1 < 10) {
                dp[i+1][j+1] += dp[i][j];
                dp[i+1][j+1] %= mod;
            }
        }
    }
    int sum = 0;
    for(int i = 0; i < 10; ++i)
        sum = (sum + dp[N][i])%mod;
    printf("%d\n", sum);

    for(int i = 0; i < 10; ++i)
        printf("dp[%d][%d]: %d\n", 2, i, dp[2][i]);

    return 0;
}