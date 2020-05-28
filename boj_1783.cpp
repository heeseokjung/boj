#include <cstdio>

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    if(N == 1) {
        printf("1\n");
    } else if(N == 2) {
        if(M <= 8)
            printf("%d\n", M/2 + M%2);
        else
            printf("4\n");
    } else {
        if(M <= 4)
            printf("%d\n", M);
        else if(M == 5)
            printf("4\n");
        else
            printf("%d\n", 2 + M - 4);
    }

    return 0;
}