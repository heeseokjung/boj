#include <stdio.h>
#include <utility>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, M;
vector<pair<int, int> > adj[501];
int is_queue[501];
int cnt[501];
int dist[501];
#define INF 1e9

void input()
{
	scanf("%d %d", &N, &M);
	int u, v, w;
	for(int i = 0; i < M; ++i) {
		scanf("%d %d %d", &u, &v, &w);
		adj[u].push_back(pair<int, int>(v, w));
	}
}

void run()
{
	for(int i = 1; i <= N; ++i)
		dist[i] = INF;
	
	dist[1] = 0; is_queue[1] = true; cnt[1]++;
	queue<int> q;
	q.push(1);
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		is_queue[u] = false;
		for(int i = 0; i < (int)adj[u].size(); ++i) {
			int v = adj[u][i].first, w = adj[u][i].second;
			if(dist[v] > dist[u] + w) {
				dist[v] = dist[u] + w;
				if(!is_queue[v]) {
					if(++cnt[v] >= N) {
						printf("-1\n");
						return;
					}
					q.push(v);
					is_queue[v] = true;
				}
			}
		}
	}
	
	for(int i = 2; i <= N; ++i)
		printf("%d\n", (dist[i] == INF) ? -1 : dist[i]);
}

int main()
{
	input();
	run();
	return 0;
}