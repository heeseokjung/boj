#include <cstdio>
#include <map>
using namespace std;

int N, M;
long long T;
long long A[1001], B[1001];
long long SUMA[1001], SUMB[1001];
map<long long, int> SA, SB;

int main() {
    scanf("%lld", &T);
    scanf("%d", &N);
    for(int i = 1; i < N+1; ++i)
        scanf("%lld", A + i);
    scanf("%d", &M);
    for(int i = 1; i < M+1; ++i)
        scanf("%lld", B + i);
    
    for(int i = 1; i < N+1; ++i)
        SUMA[i] = SUMA[i-1] + A[i];
    for(int i = 1; i < M+1; ++i)
        SUMB[i] = SUMB[i-1] + B[i];
    for(int i = 1; i < M+1; ++i) {
        for(int j = i; j < M+1; ++j) {
            auto it = SB.find(SUMB[j] - SUMB[i-1]);
            if(it == SB.end())
                SB.insert(make_pair(SUMB[j] - SUMB[i-1], 1));
            else 
                ++it->second;
        }
    }
    long long count = 0;
    for(int i = 1; i < N+1; ++i) {
        for(int j = i; j < N+1; ++j) {
            auto it = SB.find(T - (SUMA[j] - SUMA[i-1]));
            if(it != SB.end())
                count += it->second;
        }
    }
    printf("%lld\n", count);

    return 0;
}