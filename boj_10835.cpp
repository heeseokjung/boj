#include <stdio.h>
#include <algorithm>
using namespace std;

int N;
int left[2000];
int right[2000];
int memo[2000][2000];
#define INF -1

void input()
{
	scanf("%d", &N);
	for(int i = 0; i < N; ++i)
		scanf("%d", left + i);
	for(int i = 0; i < N; ++i)
		scanf("%d", right + i);
}

int dp(int i, int j)
{
	if(i == N || j == N)
		return 0;
	if(memo[i][j] != INF)
		return memo[i][j];
	int m = max(dp(i + 1, j), dp(i + 1, j + 1));
	if(left[i] > right[j])
		m = max(m, dp(i, j + 1) + right[j]);
	return memo[i][j] = m;
}

void run()
{
	for(int i = 0; i < N; ++i) {
		for(int j = 0; j < N; ++j)
			memo[i][j] = INF;
	}
	printf("%d\n", dp(0, 0));
}

int main()
{
	input();
	run();
	return 0;
}