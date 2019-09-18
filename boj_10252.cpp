#include <stdio.h>

void run()
{
    int TC, M, N;
    scanf("%d", &TC);
    while(TC--) {
        scanf("%d %d", &M, &N);
        printf("1\n");
        if(M % 2) {
            for(int i = 0; i < M; ++i) {
                if(i % 2) {
                    for(int j = N - 1; j > 0; --j)
                        printf("(%d,%d)\n", i, j);
                }
                else {
                    for(int j = i ? 1 : 0; j < N; ++j)
                        printf("(%d,%d)\n", i, j);
                }
            }
            for(int i = M - 1; i > 0; --i)
                printf("(%d,%d)\n", i, 0);
        }
        else {
            for(int i = 0; i < M; ++i) {
                if(i % 2) {
                    for(int j = N - 1; j >= 0; --j)
                        printf("(%d,%d)\n", i, j);
                }
                else {
                    for(int j = 0; j < N; ++j)
                        printf("(%d,%d)\n", i, j);
                }
            }
        }
    }
}

int main()
{
    run();
    return 0;
}