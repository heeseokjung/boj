#include <cstdio>

int N;
double map[20][20];
double memo[1<<21];

double dp(int pos, int status) {
    if(pos == N)
        return 1.0;
    if(memo[status] != -1.0)
        return memo[status];
    double ret = 0.0;
    for(int i = 0; i < N; ++i) {
        if((status & (1<<i)) == 0) {
            double tmp = map[pos][i] * dp(pos+1, status | (1<<i));
            ret = (ret < tmp) ? tmp : ret;
        }
    }
    return memo[status] = ret;
}

int main() {
    scanf("%d", &N);
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            scanf("%lf", &map[i][j]);
            map[i][j] /= 100.0;
        }
    }
    for(int i = 0; i < (1<<(N+1)); ++i)
        memo[i] = -1.0;
    printf("%.6f\n", dp(0, 0) * 100.0);
    return 0;
}