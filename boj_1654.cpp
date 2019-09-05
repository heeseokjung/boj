#include <stdio.h>

int K, N;
long long lan[10000];
long long max_len = 0;
long long ans = 0;

void input()
{
    scanf("%d %d", &K, &N);
    for(int i = 0; i < K; ++i) {
        scanf("%lld", lan + i);
        if(max_len < lan[i])
            max_len = lan[i];
    }
}

void binary_search(long long i, long long j)
{
    if(j <= i)
        return;
    long long m = (i + j)/2;
    long long count = 0;
    for(int x = 0; x < K; ++x)
        count += (lan[x] / m);
    if(count >= N) {
        if(m > ans)
            ans = m;
        binary_search(m + 1, j);
    }
    else {
        binary_search(i, m);
    }

}

void run()
{
    binary_search(1, max_len + 1);

    printf("%lld\n", ans);
}

int main()
{
    input();
    run();
    return 0;
}