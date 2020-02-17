#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<long long> v;

long long sum(long long k) {
    long long ret = 0;
    for(int i = 1; i < N; ++i) 
        ret += ((v[i] - i*k < 0) ? i*k - v[i] : v[i] - i*k);
    return ret;
}

int main() {
    scanf("%d", &N);
    v = vector<long long>(N);
    for(int i = 0; i < N; ++i)
        scanf("%lld", &v[i]);
    long long i = 1;
    long long j = v[N-1];
    long long p, q;
    while(j - i > 3) {
        p = (2*i + j)/3;
        q = (i + 2*j)/3;
        if(sum(p) > sum(q))
            i = p;
        else
            j = q;
    }
    long long ans = sum(i);
    for(long long k = i+1; k <= j; ++k)
        ans = min(ans, sum(k));
    printf("%lld\n", ans);
    return 0;
}