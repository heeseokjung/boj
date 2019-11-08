#include <stdio.h>

int A, B, C, N;

int run() {
    for(int i = 0; i*A <= N; ++i) {
        for(int j = 0; j*B <= N; ++j) {
            for(int k = 0; k*C <= N; ++k) {
                if(i*A + j*B + k*C == N)
                    return 1;
            }
        }
    }
    return 0;
}

int main() {
    scanf("%d %d %d %d", &A, &B, &C, &N);
    printf("%d\n", run());
    return 0;
}