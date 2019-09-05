#include <stdio.h>

int size;
int wine[10000];
int dp[10000];

inline int get_max(int a, int b, int c)
{
    a = (a < b) ? b : a;
    c = (a < c) ? c : a;
    return c;
}

int main()
{
    scanf("%d", &size);
    for(int i = 0; i < size; ++i)
        scanf("%d", &wine[i]);

    dp[0] = wine[0];
    dp[1] = wine[0] + wine[1];
    dp[2] = get_max(wine[0] + wine[1], wine[1] + wine[2], wine[0] + wine[2]);

    for(int i = 3; i < size; ++i) {
        dp[i] = get_max(wine[i] + wine[i - 1] + dp[i - 3], wine[i] + dp[i - 2], dp[i - 1]);
    }

    printf("%d\n", dp[size - 1]);
    
    return 0;
}