#include <stdio.h>

inline long long gcd(long long x, long long y)
{
    while(y > 0) {
        long long tmp = x;
        x = y;
        y = tmp % y;
    }
    return x;
}

void run()
{
    int TC;
    long long a, b;
    scanf("%d", &TC);
    while(TC--) {
        scanf("%lld %lld", &a, &b);
        if(a == 1) {
            printf("%lld\n", b);
            continue;
        }
        long long p = 2;
        while(true) {
            long long g = gcd(b, p);
            long long l = b * p / g;
            long long tmp = a * l / b;
            if(tmp < l / p) {
                p++;
                continue;
            }
            a = tmp - l/p;
            b = l;
            g = gcd(a, b);
            a /= g; b /= g;
            if(a == 1)
                break;
            p++;
        }
        printf("%lld\n", b);
    }
}

int main()
{
    run();
    return 0;
}