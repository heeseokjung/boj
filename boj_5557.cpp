#include <stdio.h>

int n;
typedef unsigned long long ull_t;
ull_t arr[100];
ull_t dp[100][21] = {0, };

void input()
{
    scanf("%d", &n);
    for(int i = 0; i < n; ++i)
        scanf("%lld", arr + i);
}

void run()
{
    dp[0][arr[0]]++;
    for(int i = 1; i < n - 1; ++i) {
        for(int j = 0; j <= 20; ++j) {
            if(dp[i-1][j]) {
                if(j + arr[i] <= 20 && j + arr[i] >= 0)
                    dp[i][j + arr[i]] += dp[i-1][j];
                if(j - arr[i] >= 0 && j - arr[i] <= 20)
                    dp[i][j - arr[i]] += dp[i-1][j];
            }
        }
    }
    printf("%lld\n", dp[n-2][arr[n-1]]);
}

int main()
{
    input();
    run();
    return 0;
}