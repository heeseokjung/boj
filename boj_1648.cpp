#include <stdio.h>

int N, M;
int memo[14*14][1 << 14];
#define INF -1

int dp(int pos, int s)
{
    if(pos == N*M && s == 0)
        return 1;
    if(pos >= N*M)
        return 0;
    if(memo[pos][s] != INF)
        return memo[pos][s];
    int num = 0;
    if(s & 1) {
        num = dp(pos + 1, (s >> 1));
    } else {
        num = dp(pos + 1, (s >> 1) | (1 << (M - 1)));
        if((pos % M != M - 1) && ((s & 2) == 0))
            num += dp(pos + 2, (s >> 2));
    }
    return memo[pos][s] = num % 9901;
}

void run()
{
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N * M; ++i) {
        for(int j = 0; j < (1 << M); ++j)
            memo[i][j] = INF;
    }
    printf("%d\n", dp(0, 0));
}

int main()
{
    run();
    return 0;
}