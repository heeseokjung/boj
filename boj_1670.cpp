#include <cstdio>

int N;
long long cache[10001];
#define mod 987654321

long long dp(int x) {
    if(x == 0)
        return cache[x] = 1;
    if(cache[x] != -1)
        return cache[x];
    long long count = 0;
    for(int i = 2; i <= x; i += 2) 
        count += (dp(i-2) * dp(x-i)) % mod;
    return cache[x] = count % mod;
}

int main() {
    scanf("%d", &N);
    for(int i = 0; i <= N; ++i)
        cache[i] = -1;
    printf("%lld\n", dp(N));
    return 0;
}