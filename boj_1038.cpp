#include <cstdio>
#include <cstring>

int main() {
    int N;
    scanf("%d", &N);
    long long dp[10][10];
    /*
     * i: number of most significant digit
     * j: # total digit
    */
    memset(dp, 0, sizeof(dp));
    
    for(int i = 1; i <= 9; ++i)
        dp[i][1] = 1;
    
    return 0;
}