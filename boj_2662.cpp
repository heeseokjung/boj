#include <cstdio>
#include <stack>
#include <algorithm>
using namespace std;

int N, M;
int arr[301][20];
int dp[20][301];
int memo[20][301];

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    for(int i = 1, j; i <= N; ++i) {
        scanf("%d", &j);
        for(int k = 0; k < M; ++k) {
            scanf("%d", &arr[j][k]);
        }
    }

    for(int i = 1; i <= N; ++i) {
        dp[0][i] = arr[i][0];
        memo[0][i] = i;
    }

    for(int i = 1; i < M; ++i) {
        for(int j = 0; j <= N; ++j) {
            for(int k = 0; k <= j; ++k) {
                if(dp[i][j] < arr[k][i] + dp[i-1][j-k]) {
                    dp[i][j] = arr[k][i] + dp[i-1][j-k];
                    memo[i][j] = k;
                }
            }
        }
    }

    printf("%d\n", dp[M-1][N]);
    stack<int> s;
    for(int i = M-1, j = N; i >= 0; --i) {
        s.push(memo[i][j]);
        j -= memo[i][j];
    }
    while(!s.empty()) {
        printf("%d ", s.top());
        s.pop();
    }
    printf("\n");
    
    return 0;
}