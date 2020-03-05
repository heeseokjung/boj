#include <cstdio>
#include <algorithm>
using namespace std;

int R, C;
int matrix[300][300];
long long mask[300][300][4];
bool dp[300][300][300];
char buf[310];

void precalculate() {
    for(int i = R-1; i >= 0; --i) {
        for(int j = C-1; j >= 0; --j) {
            if(i == R-1)
                mask[i][j][0] = matrix[i][j];
            else
                mask[i][j][0] = (mask[i+1][j][0] << 1) + (long long)matrix[i][j];
            if(j == C-1)
                mask[i][j][1] = matrix[i][j];
            else
                mask[i][j][1] = (mask[i][j+1][1] << 1) + (long long)matrix[i][j];
        }
    }
    for(int i = 0; i < R; ++i) {
        for(int j = 0; j < C; ++j) {
            if(i == 0)
                mask[i][j][2] = matrix[i][j];
            else
                mask[i][j][2] = (mask[i-1][j][2] << 1) + (long long)matrix[i][j];
            if(j == 0)
                mask[i][j][3] = matrix[i][j];
            else
                mask[i][j][3] = (mask[i][j-1][3] << 1) + (long long)matrix[i][j];
        }
    }
}

bool check_frame(int rr, int cc, int size) {
    int r = rr - size + 1;
    int c = cc - size + 1;
    if(r < 0 || c < 0)
        return false;
    for(int i = 0, j; i < size; i += j) {
        j = min(60, size-i);
        long long x, y;
        x = mask[r][c+i][1] & ((1LL << j) - 1);
        y = mask[rr][cc+-i][3] & ((1LL << j) - 1);
        if(x != y)
            return false;
        x = mask[r+i][c][0] & ((1LL << j) - 1);
        y = mask[rr-i][cc][2] & ((1LL << j) - 1);
        if(x != y)
            return false; 
    }
    return true;
}

int main() {
    scanf("%d %d", &R, &C);
    getchar();
    for(int i = 0; i < R; ++i) {
        fgets(buf, C+2, stdin);
        for(int j = 0; j < C; ++j)
            matrix[i][j] = buf[j] - '0';
    }
    precalculate();
    for(int i = 0; i < R; ++i)
        for(int j = 0; j < C; ++j)
            dp[i][j][0] = dp[i][j][1] = true;
    int size = min(R, C), ans = -1;
    for(int i = 1; i < R; ++i) {
        for(int j = 1; j < C; ++j) {
            for(int k = 2; k <= size; ++k) {
                if(dp[i-1][j-1][k-2] && check_frame(i, j, k)) {
                    dp[i][j][k] = true; 
                    ans = max(ans, k);
                }
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}