#include <stdio.h>

int N, L, R;
long long dp[101][101][101];

void input()
{
	scanf("%d %d %d", &N, &L, &R);
}

void run()
{
	dp[1][1][1] = 1;
	for(int i = 2; i <= N; ++i) {
		for(int j = 1; j <= L; ++j) {
			for(int k = 1; k <= R; ++k) {
				dp[i][j][k] = dp[i-1][j-1][k] + dp[i-1][j][k-1] +
					          dp[i-1][j][k] * (i - 2);
				dp[i][j][k] = dp[i][j][k] % 1000000007;
			}
		}
	}
	printf("%lld\n", dp[N][L][R]);
}

int main()
{
	input();
	run();
	return 0;
}