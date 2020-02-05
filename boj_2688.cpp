#include <cstdio>

int N;
long long dp[65][10];

int main() {
    int TC;
    scanf("%d", &TC);
    for(int i = 0; i < 10; ++i)
        dp[1][i] = 1;
    for(int i = 1; i < 65; ++i) {
        for(int j = 0; j < 10; ++j) {
            for(int k = j; k < 10; ++k) {
                dp[i+1][k] += dp[i][j];
            }
        }
    }
    while(TC--) {
        scanf("%d", &N);
        long long sum = 0;
        for(int i = 0; i < 10; ++i)
            sum += dp[N][i];
        printf("%lld\n", sum);
    }
    return 0;
}