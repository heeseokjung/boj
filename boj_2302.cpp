#include <cstdio>
#include <vector>
using namespace std;

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    vector<int> is_fixed(N+1, 0);
    for(int i = 0; i < M; ++i) {
        int x;
        scanf("%d", &x);
        is_fixed[x] = 1;
    }

    int dp[41][2];
    dp[1][0] = 1, dp[1][1] = 0;
    for(int i = 2; i <= N; ++i) {
        dp[i][0] = dp[i-1][0] + dp[i-1][1];
        if(!is_fixed[i] && !is_fixed[i-1])
            dp[i][1] = dp[i-1][0];
        else
            dp[i][1] = 0;
    }

    printf("%d\n", dp[N][0] + dp[N][1]);

    return 0;
}