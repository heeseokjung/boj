#include <cstdio>
#include <vector>
using namespace std;

int N, M;
int dp[10001];

int main() {
    int TC;
    scanf("%d", &TC);
    while(TC--) {
        scanf("%d", &N);
        vector<int> v(N);
        for(int i = 0; i < N; ++i)
            scanf("%d", &v[i]);
        scanf("%d", &M);
        for(int i = 1; i <= M; ++i)
            dp[i] = 0;
        for(int i = 0; i < N; ++i) {
            dp[v[i]]++;
            for(int j = v[i]+1; j <= M; ++j) {
                dp[j] += dp[j-v[i]];
            }
        }
        printf("%d\n", dp[M]);
    }
    return 0;
}