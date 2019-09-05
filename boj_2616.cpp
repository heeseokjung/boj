#include <stdio.h>
#include <algorithm>
using namespace std;

int n, max_train;
int train[50001];
int rsum[50001];
int dp[4][50001] = {0, };

void input()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) {
        scanf("%d", &train[i]);
        rsum[i] = rsum[i-1] + train[i];
    }
    scanf("%d", &max_train);
}

void run()
{
    for(int i = 1; i <= 3; ++i) {
        for(int j = i*max_train; j <= n; ++j) {
            dp[i][j] = max(dp[i][j-1], dp[i-1][j-max_train] + rsum[j] - rsum[j-max_train]);
        }
    }

    printf("%d\n", dp[3][n]);
}

int main()
{
    input();
    run();
    return 0;
}