#include <cstdio>

int main() {
    int N;
    scanf("%d", &N);

    bool find = false;
    int i;
    for(i = 2; i*i <= N; ++i) {
        if(N % i == 0) {
            find = true;
            break;
        }
    }

    if(find)
        printf("%d\n", N - (N/i));
    else 
        printf("%d\n", N-1);

    return 0;
}