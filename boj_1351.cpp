#include <cstdio>
#include <map>
using namespace std;

long long N, P, Q;
map<long long, long long> m;

long long seq(long long i) {
    if(i == 0)
        return 1;
    auto it = m.find(i);
    if(it != m.end())
        return it->second;
    long long val = seq(i/P) + seq(i/Q);
    m.insert({i, val});
    return val;
}

int main() {
    scanf("%lld %lld %lld", &N, &P, &Q);
    printf("%lld\n", seq(N));

    return 0;
}