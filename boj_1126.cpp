#include <cstdio>
#define HMAX 500000

int N;
int height[51];
int dp[51][HMAX+1];

inline int MAX(int x, int y) {
    return x < y ? y : x;
}

int main() {
    scanf("%d", &N);
    for(int i = 1; i <= N; ++i)
        scanf("%d", height+i);

    for(int i = 1; i <= HMAX; ++i)
        dp[0][i] = -1;

    for(int i = 1; i <= N; ++i) {
        for(int j = 0; j <= HMAX; ++j) {
            dp[i][j] = dp[i-1][j];
            if(height[i] <= j && dp[i-1][j-height[i]] != -1)
                dp[i][j] = MAX(dp[i][j], dp[i-1][j-height[i]] + height[i]);
            if(height[i] >= j && dp[i-1][height[i]-j] != -1)
                dp[i][j] = MAX(dp[i][j], dp[i-1][height[i]-j] + j);
            if(height[i] + j <= HMAX && dp[i-1][j+height[i]] != -1) 
                dp[i][j] = MAX(dp[i][j], dp[i-1][j+height[i]]);
        }
    }
    
    printf("%d\n", dp[N][0] ? dp[N][0] : -1);

    return 0;
}