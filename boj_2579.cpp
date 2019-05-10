#include <stdio.h>
#include <string.h>

#define INVALID -1

int num_stairs;
int stairs[301];
int dp[301];

inline int get_max(int a, int b);
int run(int n, bool check);

int main()
{
    scanf("%d", &num_stairs);
    for(int i = 1; i <= num_stairs; ++i)
        scanf("%d", &stairs[i]);

    memset(dp, -1, sizeof(dp));

    int ans = run(num_stairs, true);
    printf("%d\n", ans);
    
    return 0;
}

inline int get_max(int a, int b)
{
    return (a < b) ? b : a;
}

int run(int n, bool check)
{
    if(n <= 0)
        return 0;

    if(dp[n] > 0)
        return dp[n];
    
    int c1;
    if(check)
        c1 = INVALID;
    else
        c1 = run(n - 1, true) + stairs[n];
    
    int c2 = run(n - 2, false) + stairs[n];

    dp[n] = get_max(c1, c2);
    return dp[n];
}

