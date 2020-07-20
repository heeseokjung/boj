#include <cstdio>
#include <cstring>

int main() {
    int N;
    scanf("%d", &N);
    int dp[10][11];
    memset(dp, 0, sizeof(dp));
    
    for(int i = 0; i < 10; ++i)
        dp[i][1] = 1;
    for(int j = 2; j < 11; ++j) {
        dp[1][j] = 1;
        for(int i = 2; i < 10; ++i) {
            for(int k = 1; k < i; ++k) {
                dp[i][j] += dp[k][j-1];
            }
        }
    }

    N++;
    int count = 0;
    for(int j = 1; j < 11; ++j) {
        for(int i = 0; i < 10; ++i) {
            if(count + dp[i][j] < )
        }
    }
    
    return 0;
}