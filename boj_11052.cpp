#include <cstdio>
#include <algorithm>
using namespace std;

int N;
int p[1001];
int dp[1001];

int main() {
    scanf("%d", &N);
    for(int i = 1; i <= N; ++i)
        scanf("%d", p + i);
    dp[1] = p[1];
    for(int i = 2; i <= N; ++i) {
        dp[i] = p[i];
        for(int j = 1; j < i; ++j)
            dp[i] = max(dp[i], dp[j] + dp[i-j]);
    }
    printf("%d\n", dp[N]);
    return 0;
}