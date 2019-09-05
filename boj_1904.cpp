#include <stdio.h>

int n;
long long dp[1000001];

void input()
{
    scanf("%d", &n);
}

void run()
{
    dp[1] = 1;
    dp[2] = 2;
    for(int i = 3; i <= n; ++i) {
        dp[i] = (dp[i - 1] + dp[i - 2]) % 15746;
    }
    printf("%lld\n", dp[n] % 15746);
}

int main()
{
    input();
    run();

    return 0;
}