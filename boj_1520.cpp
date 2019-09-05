#include <stdio.h>
#include <string.h>

int n, m;
int arr[501][501];
int dp[501][501];

int run(int p, int q);

int main()
{
    scanf("%d %d", &m, &n);
    for(int i = 1; i <= m; ++i) {
        for(int j = 1; j <= n; ++j)
            scanf("%d", &arr[i][j]);
        memset(dp[i], -1, sizeof(int) * (n + 1));
    }

    int ans = run(1, 1);
    printf("%d\n", ans);

    return 0;
}

int run(int p, int q)
{
    if(p == m && q == n) {
        return 1;
    } else if(dp[p][q] != -1) {
        return dp[p][q];
    } else {
        dp[p][q] = 0;
        
        int sum = 0;
        if(p > 1 && arr[p][q] > arr[p - 1][q])
            sum += run(p - 1, q);
        if(p < m && arr[p][q] > arr[p + 1][q])
            sum += run(p + 1, q);
        if(q > 1 && arr[p][q] > arr[p][q - 1])
            sum += run(p, q - 1);
        if(q < n && arr[p][q] > arr[p][q + 1])
            sum += run(p, q + 1);

        dp[p][q] = sum;
        return dp[p][q];
    }

}