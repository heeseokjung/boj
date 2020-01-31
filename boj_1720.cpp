#include <cstdio>

int main() {
    int N;
    int dp[31];
    scanf("%d", &N);
    dp[1] = 1;
    dp[2] = 3;
    for(int i = 3; i <= N; ++i)
        dp[i] = dp[i-1] + 2*dp[i-2];
    if(N == 1 || N == 2)
        printf("%d\n", dp[N]);
    else if(N % 2)
        printf("%d\n", (dp[N] + dp[(N-1)/2])/2);
    else
        printf("%d\n", (dp[N] + dp[N/2] + 2*dp[(N-2)/2])/2);
    return 0;
}