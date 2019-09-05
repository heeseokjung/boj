#include <stdio.h>
#include <utility>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define INF 0x7fffffffffffffff
int n, m;
int price[2501];
pair<int, int> sorted_price[2501];
long long dist[2501][2501];
long long dp[2501];
typedef pair<long, long> ii;
vector<ii> adj[2501];

void input()
{
    scanf("%d %d", &n, &m);
    int p;
    for(int i = 1; i <= n; ++i) {
        scanf("%d", &p);
        price[i] = p;
    }
    int u, v, w;
    for(int i = 0; i < m; ++i) {
        scanf("%d %d %d", &u, &v, &w);
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }
}

void run()
{
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j)
            dist[i][j] = INF;
    }

    for(int i = 1; i <= n; ++i) {
        priority_queue<ii, vector<ii>, greater<ii> > pq;
        dist[i][i] = 0;
        pq.push(make_pair(dist[i][i], i));
        while(!pq.empty()) {
            pair<int, int> p = pq.top();
            pq.pop();
            long long d = p.first, u = p.second;
            if(dist[i][u] < d)
                continue;
            for(int j = 0; j < (int)adj[u].size(); ++j) {
                long long v = adj[u][j].first, w = adj[u][j].second;
                if(d + w < dist[i][v]) {
                    dist[i][v] = d + w;
                    pq.push(make_pair(dist[i][v], v));
                }
            }
        }
    }

    for(int i = 1; i <= n; ++i) {
        sorted_price[i].first = -price[i];
        sorted_price[i].second = i;
    }
    sort(sorted_price + 2, sorted_price + n);

    dp[1] = 0;
    for(int i = 2; i <= n; ++i) {
        int ii = sorted_price[i].second;
        dp[ii] = INF;
        for(int j = 1; j < i; ++j) {
            int jj = sorted_price[j].second;
            dp[ii] = min(dp[ii], dp[jj] + price[jj] * dist[jj][ii]);
        }
    }

    printf("%lld\n", dp[n]);
}

int main()
{
    input();
    run();
    
    return 0;
}
