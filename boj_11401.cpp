#include <cstdio>

long long N, K;
long long memo[4000001];
#define mod 1000000007

long long factorial(long long x) {
    if(x == 0 || x == 1)
        return memo[x] = 1;
    if(memo[x] != 0)
        return memo[x];
    return memo[x] = (x * factorial(x-1))%mod;
}

long long pow(long long x, long long y) {
    long long k = 1;
    while(y) {
        if(y % 2)
            k = (k*x)%mod;
        x = (x*x)%mod;
        y /= 2LL;
    }
    return k;
}

long long combination(long long n, long long k) {
    return (factorial(n) * pow((factorial(n-k)*factorial(k))%mod, mod-2))%mod;
}

int main() {
    scanf("%lld %lld", &N, &K);
    printf("%lld\n", combination(N, K));
    return 0;
}