#include <stdio.h>
#include <string.h>

#define INVALID -1

char str1[1001];
char str2[1001];
int dp[1000][1000];

int run(int i, int j);

int main()
{
    scanf("%s", str1);
    scanf("%s", str2);

    for(int i = 0; i < 1000; ++i) {
        memset(dp[i], -1, sizeof(int) * 1000);
    }

    int ans = run(strlen(str1) - 1, strlen(str2) - 1);
    printf("%d\n", ans);

    return 0;
}

int run(int i, int j)
{
    if(i < 0 || j < 0) {
        return 0;
    }
    else if(dp[i][j] != INVALID) {
        return dp[i][j];
    }
    else if(str1[i] == str2[j]) {
        dp[i][j] = run(i - 1, j - 1) + 1;
        return dp[i][j];
    }
    else {
        int c1 = run(i, j - 1);
        int c2 = run(i - 1, j);
        dp[i][j] = (c1 < c2) ? c2 : c1;
        return dp[i][j];
    }
}