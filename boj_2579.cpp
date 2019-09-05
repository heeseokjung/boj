#include <stdio.h>
#include <string.h>

#define INVALID -1

bool check = false;
int num_stairs;
int stairs[301];
int dp[301];

inline int get_max(int a, int b);
void run();

int main()
{
    scanf("%d", &num_stairs);
    for(int i = 1; i <= num_stairs; ++i)
        scanf("%d", &stairs[i]);

    memset(dp, -1, sizeof(dp));

    run();
    
    return 0;
}

inline int get_max(int a, int b)
{
    return (a < b) ? b : a;
}

void run()
{
    dp[1] = stairs[1];
    dp[2] = stairs[1] + stairs[2];
    dp[3] = get_max(stairs[1] + stairs[3], stairs[2] + stairs[3]);

    for(int i = 4; i <= num_stairs; ++i) {
        dp[i] = get_max(dp[i - 3] + stairs[i - 1] + stairs[i], dp[i - 2] + stairs[i]);
    }

    printf("%d\n", dp[num_stairs]);
}