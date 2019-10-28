#include <stdio.h>

int TC, N;
int sticker[2][100000];
int dp[100000][3];

inline int ternary_max(int x, int y, int z) {
    if(x < y)
        return y < z ? z : y;
    else
        return x < z ? z : x;
}

inline int max(int x, int y) {
    return x < y ? y : x;
}

int main() {
    scanf("%d", &TC);
    while(TC--) {
        scanf("%d", &N);
        for(int i = 0; i < 2; ++i) {
            for(int j = 0; j < N; ++j)
                scanf("%d", &sticker[i][j]);
        }
        for(int i = 0; i < N; ++i)
            dp[i][0] = dp[i][1] = dp[i][2] = 0;
        dp[0][1] = sticker[0][0]; dp[0][2] = sticker[1][0];
        for(int i = 1; i < N; ++i) {
            dp[i][0] = ternary_max(dp[i-1][0], dp[i-1][1], dp[i-1][2]);
            dp[i][1] = max(dp[i-1][0] + sticker[0][i], dp[i-1][2] + sticker[0][i]);
            dp[i][2] = max(dp[i-1][0] + sticker[1][i], dp[i-1][1] + sticker[1][i]);
        }
        printf("%d\n", ternary_max(dp[N-1][0], dp[N-1][1], dp[N-1][2]));
    }
    return 0;
}