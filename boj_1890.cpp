#include <cstdio>

int N;
int arr[100][100];
int dr[2] = {1, 0};
int dc[2] = {0, 1};
long long dp[100][100];

int main() {
    scanf("%d", &N);
    for(int i = 0; i < N; ++i)
        for(int j = 0; j < N; ++j)
            scanf("%d", &arr[i][j]);
    dp[0][0] = 1;
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            if(!dp[i][j])
                continue;
            if(i == N-1 && j == N-1)
                continue;
            int nr, nc;
            for(int k = 0; k < 2; ++k) {
                nr = i + arr[i][j]*dr[k];
                nc = j + arr[i][j]*dc[k];
                if(nr > N-1 || nc > N-1)
                    continue;
                dp[nr][nc] += dp[i][j];
            }
        }
    }
    printf("%lld\n", dp[N-1][N-1]);
    return 0;
}