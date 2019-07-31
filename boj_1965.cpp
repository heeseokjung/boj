#include <stdio.h>

int n, max_length = -1;
int box[1000];
int dp[11000];

void input()
{
    scanf("%d", &n);
    for(int i = 0; i < n; ++i)
        scanf("%d", box + i);
}

void run()
{
    for(int i = 0; i < n; ++i) {
        dp[i] = 1;
        for(int j = 0; j < i; ++j) {
            if(box[j] < box[i] && dp[j] + 1 > dp[i])
                dp[i] = dp[j] + 1;
        }
        if(dp[i] > max_length)
            max_length = dp[i];
    }
    printf("%d\n", max_length);
}

int main()
{
    input();
    run();
    return 0;
}