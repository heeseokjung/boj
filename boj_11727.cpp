#include <cstdio>

int main() {
    int N;
    scanf("%d", &N);
    int dp[1001];
    for(int i = 1; i <= N; ++i)
        dp[i] = 0;

    dp[1] = 1;
    dp[2] = 3;
    const int mod = 10007;
    for(int i = 3; i <= N; ++i)
        dp[i] = (dp[i-1] + 2*dp[i-2]) % mod;

    printf("%d\n", dp[N]);

    return 0;
}