#include <cstdio>

int main() {
    int TC;
    scanf("%d", &TC);
    while(TC--) {
        long long N;
        scanf("%lld", &N);
        long long mx = N;
        while(N != 1) {
            mx = (mx < N) ? N : mx;
            if(N % 2 == 0)
                N /= 2;
            else
                N = 3*N + 1;
        }
        printf("%lld\n", mx);
    }
    return 0;
}