#include <cstdio>
#include <utility>
#include <vector>
using namespace std;

int N, M;
vector<pair<int, int> > adj[501];
long long dist[501];
const long long inf = (int)1e10;

int main() {
	scanf("%d %d", &N, &M);
	for(int i = 0; i < M; ++i) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		adj[u].push_back({v, w});
	}

	for(int i = 1; i <= N; ++i)
		dist[i] = inf;

	dist[1] = 0;
	for(int i = 0; i < N; ++i) {
		for(int u = 1; u <= N; ++u) {
			for(pair<int, int> p : adj[u]) {
				int v = p.first;
				long long w = (long long)p.second;
				if(dist[u] != inf && dist[u] + w < dist[v]) {
					if(i == N-1) {
						printf("-1\n");
						return 0;
					} else {
						dist[v] = dist[u] + w;
					}
				}
			}
		}
	}

	for(int i = 2; i <= N; ++i)
		printf("%lld\n", dist[i] == inf ? -1 : dist[i]);

	return 0;
}