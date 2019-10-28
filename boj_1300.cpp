#include <stdio.h>

int main() {
    int N, K;
    scanf("%d %d", &N, &K);
    int l = 1, r = K;
    long long sum;
    while(l < r) {
        int m = (l + r)/2;
        sum = 0;
        for(int i = 1; i <= N; ++i) 
            sum += (m/i > N) ? (long long)N : (long long)m/i;
        if(sum >= K)
            r = m;
        else
            l = m + 1;
    }
    printf("%d\n", r);
}