#include <stdio.h>

int size;
int seq[1000];
int dp[1000];

void run();

int main()
{
    scanf("%d", &size);
    for(int i = 0; i < size; ++i)
        scanf("%d", &seq[i]);

    run();
    
    return 0;
}

void run()
{
    int lis_length = 1;
    dp[0] = 1;
    for(int i = 0; i < size; ++i) {
        int max_length = 1;
        for(int j = 0; j < i; ++j) {
            if(seq[j] < seq[i] && dp[j] + 1 > max_length)
                max_length = dp[j] + 1;
        }
        if(max_length > lis_length)
            lis_length = max_length;
        dp[i] = max_length;
    }

    printf("%d\n", lis_length);
}