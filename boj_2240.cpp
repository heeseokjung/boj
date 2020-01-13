#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int T, W;
vector<int> v;
int dp[1001][2][31];

int main() {
    scanf("%d %d", &T, &W);
    v = vector<int>(T+1);
    for(int i = 1; i <= T; ++i)
        scanf("%d", &v[i]);
    dp[1][0][0] = (v[1] == 1) ? 1 : 0;
    dp[1][1][1] = (v[1] == 2) ? 1 : 0;
    int ans = max(dp[1][0][0], dp[1][1][1]);
    for(int i = 2; i <= T; ++i) {
        for(int j = 0; j < 2; ++j) {
            for(int k = 0; k <= i && k <= W; ++k) {
                if(v[i] == j+1) {
                    dp[i][j][k] = max(dp[i][j][k], dp[i-1][j][k] + 1);
                    if(k > 0)
                        dp[i][j][k] = max(dp[i][j][k], dp[i-1][1-j][k-1] + 1);
                }
                else {
                    dp[i][j][k] = max(dp[i][j][k], dp[i-1][j][k]);
                    if(k > 0)
                        dp[i][j][k] = max(dp[i][j][k], dp[i-1][1-j][k-1]);
                }
                ans = max(ans, dp[i][j][k]);
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}