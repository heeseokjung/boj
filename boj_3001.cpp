#include <cstdio>
#include <cstring>

int S;
long long A, B;
long long pow[16];
long long cache[16][136];
long long min_value = -1;

long long dp(long long prefix, int digit, int sum) {
    if(sum < 0)
        return 0LL;

    long long mn = prefix;
    long long mx = prefix + pow[digit] - 1;

    if(mn > B || mx < A)
        return 0LL;
    
    if(digit == 0) {
        if(sum > 0)
            return 0LL;
        if(min_value == -1)
            min_value = prefix;
        return 1LL;
    }

    if(A <= mn && B >= mx && cache[digit][sum] != -1)
        return cache[digit][sum];

    long long count = 0;
    for(int x = 0; x < 10; ++x)
        count += dp(prefix + x*pow[digit-1], digit - 1, sum - x);
    
    if(A <= mn && B >= mx)
        cache[digit][sum] = count;

    return count;
}

int main() {
    scanf("%lld %lld %d", &A, &B, &S);

    pow[0] = 1;
    for(int i = 1; i < 16; ++i)
        pow[i] = pow[i-1]*10LL;
    memset(cache, -1, sizeof(cache));

    printf("%lld\n", dp(0, 15, S));
    printf("%lld\n", min_value);

    return 0;
}