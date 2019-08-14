#include <stdio.h>

int N, K, S;
int adj[401][401];

void input()
{
	scanf("%d %d", &N, &K);
	int u, v;
	for(int i = 0; i < K; ++i) {
		scanf("%d %d", &u, &v);
		adj[u][v] = -1;
		adj[v][u] = 1;
	}
}
void run()
{
	for(int k = 1; k <= N; ++k) {
		for(int i = 1; i <= N; ++i) {
			for(int j = 1; j <= N; ++j) {
				if(adj[i][k] == -1 && adj[k][j] == -1) {
					adj[i][j] = -1;
					adj[j][i] = 1;
				}
			}
		}
	}
	
	scanf("%d", &S);
	int x, y;
	for(int i = 0; i < S; ++i) {
		scanf("%d %d", &x, &y);
		printf("%d\n", adj[x][y]);
	}
}

int main()
{
	input();
	run();
	return 0;
}