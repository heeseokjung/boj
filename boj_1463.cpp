#include <stdio.h>
#include <string.h>

#define INF 1000000000

int num;
int dp[1000001];

int run(int n);
inline int get_min(int a, int b, int c);

int main()
{
    scanf("%d", &num);
    memset(dp, -1, sizeof(int)*(num + 1));

    dp[1] = 0;
    int ans = run(num);

    printf("%d\n", ans);
    
    return 0;
}

int run(int n)
{
    if(dp[n] != -1)
        return dp[n];
    
    int c1 = INF, c2 = INF, c3 = INF;
    if(n % 3 == 0)
        c1 = run(n / 3) + 1;
    if(n % 2 == 0)
        c2 = run(n / 2) + 1;
    c3 = run(n - 1) + 1;

    dp[n] = get_min(c1, c2, c3);
    
    return dp[n];
}

inline int get_min(int a, int b, int c)
{
    int ret = (a < b) ? a : b;
    ret = (ret < c) ? ret : c;
    return ret;
}