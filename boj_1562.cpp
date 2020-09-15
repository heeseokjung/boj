#include <cstdio>

int N;
int dp[101][10];
const int mod = (int)1e9;

inline int abs(int x) {
    return x < 0 ? -x : x;
}

int main() {
    scanf("%d", &N);
    for(int i = 0; i < 10; ++i)
        dp[1][i] = 1;
    for(int i = 2; i <= N; ++i) {
        for(int j = 0; j < 10; ++j) {
            if(j-1 >= 0)  {
                if(j-1 == 0 && i == 2)
                    ;
                else
                    dp[i][j] = (dp[i][j] + dp[i-1][j-1])%mod;
            }
            if(j+1 < 10) {
                dp[i][j] = (dp[i][j] + dp[i-1][j+1])%mod;
            }
        }
    }
    int sum = 0;
    for(int i = 0; i < 10; ++i)
        sum = (sum + dp[N][i])%mod;
    printf("%d\n", sum);

    for(int i = 0; i < 10; ++i)
        printf("dp[%d][%d]: %d\n", 2, i, dp[2][i]);

    return 0;
}