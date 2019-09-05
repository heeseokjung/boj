#include <stdio.h>
#include <algorithm>
using namespace std;

#define INVALID -1
#define INF 2000000000
int n, m;
bool day[101] = {false, };
int dp[101][101];

void input()
{
    scanf("%d %d", &n, &m);
    int x;
    for(int i = 0; i < m; ++i) {
        scanf("%d", &x);
        day[x] = true;
    }

    for(int i = 1; i <= n; ++i) {
        for(int j = 0; j <= i; ++j)
            dp[i][j] = -1;
    }
}

int cal(int d, int c)
{
    if(d > n)
        return 0;
    if(dp[d][c] != INVALID)
        return dp[d][c];
    if(day[d])
        return dp[d][c] = cal(d + 1, c);
    
    int cost = INF;
    if(c >= 3)
        cost = min(cost, cal(d + 1, c - 3));
    cost = min(cost, cal(d + 1, c) + 10000);
    cost = min(cost, cal(d + 3, c + 1) + 25000);
    cost = min(cost, cal(d + 5, c + 2) + 37000);

    dp[d][c] = cost;
    return dp[d][c];
}

int run(int day, int coupon)
{
    int ans = cal(day, coupon);
    printf("%d\n", ans);
}

int main()
{
    input();
    run(1, 0);
   
    return 0;
}