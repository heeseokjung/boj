#include <cstdio>

int N;
int dp[100000][3];

int main() {
    scanf("%d", &N);
    for(int i = 0; i < 3; ++i)
        dp[0][i] = 1;
    for(int i = 1; i < N; ++i) {
        dp[i][0] = ((dp[i-1][0] + dp[i-1][1])%9901 + dp[i-1][2])%9901;
        dp[i][1] = (dp[i-1][0] + dp[i-1][2])%9901;
        dp[i][2] = (dp[i-1][0] + dp[i-1][1])%9901;
    }
    printf("%d\n", ((dp[N-1][0] + dp[N-1][1])%9901 + dp[N-1][2])%9901);
    return 0;
}