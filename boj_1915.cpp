#include <cstdio>
#include <algorithm>
using namespace std;

int N, M;
int arr[1001][1001];
int dp[1001][10001];
char buf[1010];

int main() {
    scanf("%d %d", &N, &M);
    getchar();
    for(int i = 1; i <= N; ++i) {
        fgets(buf, M+2, stdin);
        for(int j = 1; j <= M; ++j) {
            arr[i][j] = buf[j-1] - '0';
            if(arr[i][j])
                dp[i][j] = 1;
        }
    }
    int ans = 0;
    for(int i = 1; i <= N; ++i) {
        for(int j = 1; j <= M; ++j) {
            if(arr[i][j]) {
                dp[i][j] = min(min(dp[i][j-1], dp[i-1][j]), dp[i-1][j-1]) + 1;
                ans = max(ans, dp[i][j]);
            }
        }
    }
    printf("%d\n", ans*ans);
    return 0;
}