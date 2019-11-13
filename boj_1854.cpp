#include <cstdio>
#include <utility>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, M, K;
vector<pair<int, int> > adj[1001];
priority_queue<int> dv[1001];

int main() {
    scanf("%d %d %d", &N, &M, &K);
    int x, y, z;
    for(int i = 0; i < M; ++i) {
        scanf("%d %d %d", &x, &y, &z);
        adj[x].push_back(pair<int, int>(y, z));
    }
    typedef pair<int, int> ii;
    priority_queue<ii, vector<ii>, greater<ii> > pq;
    pq.push(pair<int, int>(0, 1));
    dv[1].push(0);
    int u, d;
    while(!pq.empty()) {
        d = pq.top().first;
        u = pq.top().second;
        pq.pop();
        int size = (int)adj[u].size();
        for(int i = 0; i < size; ++i) {
            if(dv[adj[u][i].first].size() < K) {
                dv[adj[u][i].first].push(d + adj[u][i].second);
                pq.push(pair<int, int>(d + adj[u][i].second, adj[u][i].first));
            }
            else if(dv[adj[u][i].first].top() > d + adj[u][i].second) {
                dv[adj[u][i].first].pop();
                dv[adj[u][i].first].push(d + adj[u][i].second);
                pq.push(pair<int, int>(d + adj[u][i].second, adj[u][i].first));
            }
        }
    }
    for(int i = 1; i <= N; ++i) {
        if(dv[i].size() < K) {
            printf("-1\n");
        }
        else {
            printf("%d\n", dv[i].top());
        }
    }
    return 0;
}