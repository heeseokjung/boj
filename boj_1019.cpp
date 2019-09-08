#include <stdio.h>

int N;
long long count[10];
long long c[10];

void adjust(int x, long long y)
{
    while(x) {
        count[x % 10] += y;
        x /= 10;
    }
}

void run()
{
    scanf("%d", &N);
    int p = 1, q = N;
    long long r = 1;
    while(q) {
        while(p <= q) {
            if(p <= q && p % 10 != 0)
                adjust(p++, r);
            if(p <= q && q % 10 != 9)
                adjust(q--, r);
            if(p % 10 == 0 && q % 10 == 9)
                break;
        }
        if(p % 10 == 0 && q % 10 == 9) {
            for(int i = 0; i < 10; ++i)
                count[i] += r * (q/10 - p/10 + 1);
        }
        r = r * 10;
        p = p / 10;
        q = q / 10;
    }

    for(int i = 0; i < 10; ++i)
        printf("%lld ", count[i]);
    printf("\n");
}

int main()
{
    run();
    return 0;
}