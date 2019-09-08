#include <stdio.h>

int N, M;
char buf[110];
long long num[101][101];
long long rsum[101][101];

void input()
{
    scanf("%d %d", &N, &M);
    for(int i = 1; i <= N; ++i) {
        scanf("%s", buf);
        for(int j = 0; j < M; ++j)
            num[i][j+1] = buf[j] - '0';
    }
}

inline long long getRsum(int a, int b, int c, int d)
{
    return rsum[c][d] - rsum[a-1][d] - rsum[c][b-1] + rsum[a-1][b-1]; 
}

void run() 
{
    for(int i = 1; i <= N; ++i) {
        for(int j = 1; j <= M; ++j)
            rsum[i][j] = rsum[i][j-1] + num[i][j];
    }
    for(int j = 1; j <= M; ++j) {
        for(int i = 1; i <= N; ++i)
            rsum[i][j] += rsum[i-1][j];
    }

    long long s1, s2, s3, max = 0;
    for(int i = 1; i < N - 1; ++i) {
        for(int j = i + 1; j < N; ++j) {
            s1 = getRsum(1, 1, i, M);
            s2 = getRsum(i + 1, 1, j, M);
            s3 = getRsum(j + 1, 1, N, M);
            max = (max < s1*s2*s3) ? s1*s2*s3 : max;
        }
    }
    for(int i = 1; i < M - 1; ++i) {
        for(int j = i + 1; j < M; ++j) {
            s1 = getRsum(1, 1, N, i);
            s2 = getRsum(1, i + 1, N, j);
            s3 = getRsum(1, j + 1, N, M);
            max = (max < s1*s2*s3) ? s1*s2*s3 : max;
        }
    }
    for(int i = 1; i < N; ++i) {
        for(int j = 1; j < M; ++j) {
            s1 = getRsum(1, 1, i, j);
            s2 = getRsum(1, j + 1, i, M);
            s3 = getRsum(i + 1, 1, N, M);
            max = (max < s1*s2*s3) ? s1*s2*s3 : max;
            s1 = getRsum(1, 1, i, j);
            s2 = getRsum(i + 1, 1, N, j);
            s3 = getRsum(1, j + 1, N, M);
            max = (max < s1*s2*s3) ? s1*s2*s3 : max;
            s1 = getRsum(1, 1, i, M);
            s2 = getRsum(i + 1, 1, N, j);
            s3 = getRsum(i + 1, j + 1, N, M);
            max = (max < s1*s2*s3) ? s1*s2*s3 : max;
            s1 = getRsum(1, 1, N, j);
            s2 = getRsum(1, j + 1, i, M);
            s3 = getRsum(i + 1, j + 1, N, M);
            max = (max < s1*s2*s3) ? s1*s2*s3 : max;
        }
    }
    printf("%lld\n", max);
}

int main()
{
    input();
    run();
    return 0;
}