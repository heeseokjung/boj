#include <cstdio>

int N, M, X, Y;
int arr[100];

int main() {
    int TC;
    scanf("%d", &TC);
    while(TC--) {
        scanf("%d %d", &N, &M);
        scanf("%d", &X);
        for(int i = 1, j; i < M; ++i) {
            scanf("%d", &j);
            X = X*10 + j;
        }
        scanf("%d", &Y);
        for(int i = 1, j; i < M; ++i) {
            scanf("%d", &j);
            Y = Y*10 + j;
        }
        for(int i = 0; i < N; ++i)
            scanf("%d", arr+i);
        int count = 0;
        for(int i = 0; i < N; ++i) {
            int Z = arr[i];
            for(int j = 1; j < M; ++j)
                Z = Z*10 + arr[(i+j)%N];
            if(X <= Z && Z <= Y)
                count++;
        }
        printf("%d\n", count);
    }
    return 0;
}