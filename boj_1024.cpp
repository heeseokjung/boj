#include <cstdio>

int main() {
    int N, L;
    scanf("%d %d", &N, &L);

    int start;
    while(L <= 100) {
        if((N*2) % L == 0 && ((2*N)/L - (L-1)) % 2 == 0 && (2*N)/L - (L-1) >= 0) {
            start = ((2*N)/L - (L-1)) / 2;
            break;
        }
        L++;
    }

    if(L > 100) {
        printf("-1\n");
    } else {
        for(int i = 0; i < L; ++i)
            printf("%d ", start + i);
        printf("\n");
    }

    return 0;
}