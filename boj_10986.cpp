#include <stdio.h>

long long N, M;
long long num[1000001];
long long rsum[1000001];
long long cnt[1000];

void input()
{
    scanf("%lld %lld", &N, &M);
    for(int i = 1; i <= N; ++i)
        scanf("%lld", num + i);
}

void run()
{
    for(int i = 1; i <= N; ++i) {
        rsum[i] = rsum[i-1] + num[i];
        ++cnt[rsum[i] % M];
    }
    long long ans = 0;
    for(int i = 0; i < M; ++i)
        ans += cnt[i] * (cnt[i] - 1) / 2;
    ans += cnt[0];
    printf("%lld\n", ans);
}

int main()
{
    input();
    run();
    return 0;
}