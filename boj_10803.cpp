#include <stdio.h>
#include <algorithm>
using namespace std;

int N, M;
int memo[10001][101];

int dp(int i, int j)
{
	if(memo[i][j] != -1)
		return memo[i][j];
	else if(i == j)
		return memo[i][j] = 1;
	int m = i * j;
	if(i >= 3 * j)
		return min(m, dp(i - j, j) + 1);
	for(int k = 1; k <= i/2; ++k)
		m = min(m, dp(k, j) + dp(i - k, j));
	for(int k = 1; k <= j/2; ++k)
		m = min(m, dp(i, k) + dp(i, j - k));
	return memo[i][j] = m;
}

void run()
{
	scanf("%d %d", &N, &M);
	for(int i = 1; i <= N; ++i) {
		for(int j = 1; j <= M; ++j) {
			memo[i][j] = -1;
		}
	}
	printf("%d\n", dp(N, M));
}

int main()
{
	run();
	return 0;
}