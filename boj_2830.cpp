#include <cstdio>
#include <vector>
using namespace std;

long long N;
long long count[21];
vector<long long> v;

int main() {
    scanf("%lld", &N);
    v = vector<long long>(N);
    for(int i = 0; i < N; ++i) {
        scanf("%lld", &v[i]);
        for(int j = 0; j < 21; ++j) {
            if((1 << j) & v[i])
                count[j]++;
        }
    }
    long long ans = 0;
    for(int i = 0; i < 21; ++i)
        ans += count[i]*(N - count[i])*(1 << i);
    printf("%lld\n", ans);
    return 0;
}