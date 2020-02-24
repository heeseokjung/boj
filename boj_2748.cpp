#include <cstdio>

int main() {
    int N;
    scanf("%d", &N);
    typedef unsigned long long ull_t;
    ull_t dp[91];
    dp[0] = 0LL;
    dp[1] = 1LL;
    for(int i = 2; i <= N; ++i)
        dp[i] = dp[i-1] + dp[i-2];
    printf("%lld\n", dp[N]);
    return 0;
}