#include <stdio.h>
#include <algorithm>

int n;
int dp[50001];

void input()
{
    scanf("%d", &n);
}

void run()
{
    for(int i = 1; i <= 5; ++i) {
        if(i == 3 || i == 5)
            dp[i] = 1;
        else 
            dp[i] = -1;
    }

    for(int i = 6; i <= n; ++i) {
        if(dp[i-3] == -1 && dp[i-5] == -1) {
            dp[i] = -1;
        }
        else if(dp[i-3] == -1) {
            dp[i] = dp[i-5] + 1;
        }
        else if(dp[i-5] == -1) {
            dp[i] = dp[i-3] + 1;
        }
        else {
            dp[i] = std::min(dp[i-3], dp[i-5]) + 1;
        }
    }

    printf("%d\n", dp[n]);
}

int main()
{
    input();
    run();

    return 0;
}