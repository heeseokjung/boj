#include <stdio.h>

int TC, N;
long long dp[1001];

inline long long trim(long long x) {
    while(x % 10 == 0)
        x /= 10;
    return x;
}

long long fibonacci(long long x) {
    if(x == 1) {
        return 1;
    }
    if(dp[x] != -1) {
        return dp[x];
    }
    return dp[x] = trim(trim(x) * trim(fibonacci(x - 1))) % 10000000000;
}

int main() {
    scanf("%d", &TC);
    while(TC--) {
        scanf("%d", &N);
        for(int i = 1; i <= N; ++i)
            dp[i] = -1;
        printf("%lld\n", fibonacci((long long)N) % 10);
    }
    return 0;
}