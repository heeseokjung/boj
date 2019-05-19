#include <stdio.h>

int n, k;
int coin[101];
int dp[10001] = {0, };

int run(int type, int value);

int main()
{
    scanf("%d %d", &n, &k);
    for(int i = 1; i <= n; ++i)
        scanf("%d", &coin[i]);

    int ans = run(1, k);
    printf("%d\n", ans);

    return 0;
}

int run(int type, int value)
{
    dp[0] = 1;

    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= k; ++j) {
            if(j >= coin[i])
                dp[j] += dp[j - coin[i]];
        }
    }

    return dp[k];
}