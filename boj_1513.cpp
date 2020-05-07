#include <cstdio>
#include <cstring>

int N, M, C;
int point_num[51][51];
int memo[51][51][51][51];
#define MOD 1000007

int dp(int i, int j, int k, int count) {
    if(i < 1 || j < 1 || i > N || j > M)
        return 0;
    if(memo[i][j][k][count] != -1)
        return memo[i][j][k][count];
    if(!point_num[i][j]) {
        return memo[i][j][k][count] = (dp(i-1, j, k, count) + dp(i, j-1, k, count)) % MOD;
    } else if(point_num[i][j] == k) {
        int ret = 0;
        for(int x = 0; x < k; ++x) {
            ret += (dp(i-1, j, x, count-1) + dp(i, j-1, x, count-1)) % MOD;
            ret %= MOD;
        }
        return memo[i][j][k][count] = ret;
    } else {
        return memo[i][j][k][count] = 0;
    }
}

int main() {
    scanf("%d %d %d", &N, &M, &C);
    int r, c;
    for(int i = 1; i <= C; ++i) {
        scanf("%d %d", &r, &c);
        point_num[r][c] = i;
    }

    memset(memo, -1, sizeof(memo));

    if(!point_num[1][1])
        memo[1][1][0][0] = 1;
    else
        memo[1][1][point_num[1][1]][1] = 1;

    for(int i = 0; i <= C; ++i) {
        int ans = 0;
        for(int j = 0; j <= C; ++j) {
            ans += dp(N, M, j, i);
            ans %= MOD;
        }
        printf("%d ", ans);
    }
    printf("\n");

    return 0;
}