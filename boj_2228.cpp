#include <cstdio>
#include <algorithm>
using namespace std;

int N, M;
int arr[101];
int rsum[101];
int dp[101][51];

int main() {
    scanf("%d %d", &N, &M);
    for(int i = 1; i <= N; ++i)
        scanf("%d", arr+i);
    for(int i = 1; i <= N; ++i)
        rsum[i] = rsum[i-1] + arr[i];
    for(int i = 0; i <= M; ++i)
        dp[0][i] = -1e9;
    for(int i = 1; i <= N; ++i) {
        for(int j = 1; j <= M; ++j) {
            dp[i][j] = dp[i-1][j];
            for(int k = i; k > 0; --k) {
                int c;
                if(j == 1)
                    c = 0;
                else if(k <= 2)
                    c = -1e9;
                else
                    c = dp[k-2][j-1];
                dp[i][j] = max(dp[i][j], c + rsum[i] - rsum[k-1]);
            }
        }
    }
    printf("%d\n", dp[N][M]);
    return 0;
}