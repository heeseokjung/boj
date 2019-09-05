#include <stdio.h>

long n, b, c;
long long num[1000000];
long long num_general = 0, num_assistant = 0;

void input()
{
    scanf("%lld", &n);
    for(int i = 0; i < n; ++i)
        scanf("%lld", num + i);
    scanf("%lld %lld", &b, &c);
}

void run()
{
    for(int i = 0; i < n; ++i) {
        num_general++;
        if(num[i] <= b)
            continue;
        int tmp = num[i] - b;
        num_assistant += (tmp / c);
        if(tmp % c != 0)
            num_assistant++;
    }

    printf("%lld\n", num_general + num_assistant);
}

int main()
{
    input();
    run();

    return 0;
}