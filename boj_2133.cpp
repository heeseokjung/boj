#include <cstdio>

int N;
int dp[31];

int main() {
    scanf("%d", &N);
    dp[0] = 1;
    dp[2] = 3;
    for(int i = 1; i <= N; ++i) {
        if(i > 2)
            dp[i] += dp[i-2] * 3;
        for(int j = 4; i-j >= 0; j += 2)
            dp[i] += dp[i-j] * 2;
    }
    printf("%d\n", dp[N]);
}