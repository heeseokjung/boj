#include <stdio.h>

int N, M;
int A[50][50], B[50][50];

inline void complement(int x, int y, int z, int w) {
    for(int i = x; i <= z; ++i) {
        for(int j = y; j <= w; ++j)
            A[i][j] = 1 - A[i][j];
    }
}

int main() {
    scanf("%d %d", &N, &M);
    char c; getchar();
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < M; ++j) {
            scanf("%c", &c);
            A[i][j] = c - '0';
        }
        getchar();
    }
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < M; ++j) {
            scanf("%c", &c);
            B[i][j] = c - '0';
        }
        getchar();
    }

    if(N < 3 || M < 3) {
        for(int i = 0; i < N; ++i) {
            for(int j = 0; j < M; ++j) {
                if(A[i][j] != B[i][j]) {
                    printf("-1\n");
                    return 0;
                }
            }
        }
        printf("0\n");
    }
    else {
        int count = 0;
        for(int i = 0; i < N-2; ++i) {
            for(int j = 0; j < M-2; ++j) {
                if(A[i][j] != B[i][j]) {
                    complement(i, j, i+2, j+2);
                    ++count;
                }
            }
        }
        for(int i = 0; i < N; ++i) {
            for(int j = 0; j < M; ++j) {
                if(A[i][j] != B[i][j]) {
                    printf("-1\n");
                    return 0;
                }
            }
        }
        printf("%d\n", count);
    }
    return 0;
}