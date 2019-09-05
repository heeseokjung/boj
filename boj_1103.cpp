#include <stdio.h>

int N, M;
int board[51][51];
int dp[51][51];
bool visit[51][51];
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

void input()
{
	scanf("%d %d", &N, &M);
	getchar();
	char c;
	for(int i = 1; i <= N; ++i) {
		for(int j = 1; j <= M; ++j) {
			scanf("%c", &c);
			if(c == 'H')
				board[i][j] = 0;
			else
				board[i][j] = c - '0';
		}
		getchar();
	}
}

int dfs(int r, int c, int d)
{
	if(r < 1 || r > N || c < 1 || c > M) 
		return 0;
	else if(!board[r][c])              
		return 0;
	else if(dp[r][c])
		return dp[r][c];
	else if(visit[r][c])
		return -1;
	visit[r][c] = true;
	int nr, nc, len, max = 0;
	for(int i = 0; i < 4; ++i) {
		nr = r + dr[i]*board[r][c];
		nc = c + dc[i]*board[r][c];
		len = dfs(nr, nc, d + 1);
		if(len == -1)
			return -1;
		max = (max < len) ? len : max;
	}
	visit[r][c] = false;
	return dp[r][c] = max + 1;
}

void run()
{
	printf("%d\n", dfs(1, 1, 0));
}

int main()
{
	input();
	run();
	return 0;
}