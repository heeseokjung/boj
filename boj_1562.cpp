#include <cstdio>
#define MOD 1000000000

int N;
int dp[101][10][2100];

int main() {
    scanf("%d", &N);
    
    for(int i = 1, j = 1; i < 10; ++i)
        dp[1][i][j<<i] = 1;
    for(int i = 2; i <= N; ++i) {
        for(int j = 0; j < 10; ++j) {
            for(int k = 0; k < (1<<10); ++k) {
                if(j-1 >= 0)
                    dp[i][j][k | (1<<j)] += dp[i-1][j-1][k];
                if(j+1 < 10)
                    dp[i][j][k | (1<<j)] += dp[i-1][j+1][k];
                dp[i][j][k] %= MOD;
            }
        }
    }

    int sum = 0;
    for(int i = 0; i < 10; ++i) {
        for(int j = 0; j < (1<<10); ++j) {
            if(j == (1<<10)-1)
                sum += dp[N][i][j];
            sum %= MOD;
        }
    }
    printf("%d\n", sum);

    return 0;
}