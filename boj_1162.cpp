#include <stdio.h>
#include <utility>
#include <vector>
#include <queue>
using namespace std;

int N, M, K;
vector<pair<int, int> > adj[10001];
long long dist[10001][21];
#define INF 1e15

void input()
{
	scanf("%d %d %d", &N, &M, &K);
	int u, v, w;
	for(int i = 0; i < M; ++i) {
		scanf("%d %d %d", &u, &v, &w);
		adj[u].push_back(pair<int, int>(v, w));
		adj[v].push_back(pair<int, int>(u, w));
	}
}

void run()
{
	for(int i = 1; i <= N; ++i) {
		for(int j = 0; j < 21; ++j) {
			dist[i][j] = INF;
		}
	}
	
	typedef pair<int, int> ii;
	typedef pair<long long, ii> iii;
	priority_queue<iii, vector<iii>, greater<iii> > pq;
	dist[1][0] = 0;
	pq.push(iii(dist[1][0], ii(1, 0)));
	int u, count; long long w;
	while(!pq.empty()) {
		iii p = pq.top(); pq.pop();
		w = p.first;
		u = p.second.first;
		count = p.second.second;
		if(dist[u][count] < w)
			continue;
		for(int i = 0; i < (int)adj[u].size(); ++i) {
			if(dist[u][count] + adj[u][i].second < dist[adj[u][i].first][count]) {
				dist[adj[u][i].first][count] = dist[u][count] + adj[u][i].second;
				pq.push(iii(dist[adj[u][i].first][count], ii(adj[u][i].first, count)));
			}
			if(count < K && dist[u][count] < dist[adj[u][i].first][count+1]) {
				dist[adj[u][i].first][count+1] = dist[u][count];
				pq.push(iii(dist[adj[u][i].first][count+1], ii(adj[u][i].first, count + 1)));
			}
		}
	}
	
	long long ans = INF;
	for(int i = 0; i <= K; ++i) {
		if(dist[N][i] < ans)
			ans = dist[N][i];
	}
	printf("%lld\n", ans);
}

int main()
{
	input();
	run();
	return 0;
}