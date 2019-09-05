#include <stdio.h>

int n;
long long dp[2][91];

void input()
{
	scanf("%d", &n);
}

long long recursion(int cur, int depth)
{
	if(dp[cur][depth] != -1)
		return dp[cur][depth];
	
	if(cur == 1)  {
		return dp[cur][depth] = recursion(0, depth - 1);
	}
	else {
		return dp[cur][depth] = (recursion(0, depth - 1) + recursion(1, depth - 1));
	}
}

void run()
{
	for(int i = 0; i <= 1; ++i) {
		for(int j = 1; j <= 90; ++j) { 
			dp[i][j] = -1;
		}
	}
	dp[0][1] = 0;
	dp[1][1] = 1;
	
	printf("%lld\n", recursion(0, n) + recursion(1, n));
}

int main()
{
	input();
	run();
	
	return 0;
}