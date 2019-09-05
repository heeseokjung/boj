#include <stdio.h>
#include <algorithm>
using namespace std;

#define INF 1000000000
int n;
int dp[100001];

void input()
{
    scanf("%d", &n);
}

int recursive(int x)
{
    if(dp[x] != -1)
        return dp[x];
    int i = 1, count = INF;
    while(i*i <= x) {
        count = min(count, 1 + recursive(x - i*i));
        i++;
    }
    return dp[x] = count;
}

void run()
{
    for(int i = 1; i <= n; ++i)
        dp[i] = -1;
    dp[0] = 0;
    int x = 1;
    while(x*x <= n) {
        dp[x*x] = 1;
        x++;
    }

    recursive(n);

    printf("%d\n", dp[n]);
}

int main()
{
    input();
    run();
    return 0;
}