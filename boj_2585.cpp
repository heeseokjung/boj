#include <stdio.h>
#include <math.h>
#include <utility>
#include <vector>
#include <queue>
using namespace std;

int N, K;
vector<pair<int, int> > node;
vector<int> stop;
int adj[1002][1002];
bool visit[1002];

inline int getFuel(pair<int, int>& p1, pair<int, int>& p2) {
    double d = sqrt((p1.first-p2.first)*(p1.first-p2.first) + (p1.second-p2.second)*(p1.second-p2.second));
    d = ceil(d);
    return ((long long)d/10LL) + ((long long)d%10LL ? 1 : 0);
}

bool bfs(int limit) {
    for(int i = 0; i < N+2; ++i)
        visit[i] = false;
    queue<pair<int, int> > q;
    visit[0];
    q.push(pair<int, int>(0, 0));
    int u, d;
    while(!q.empty()) {
        u = q.front().first;
        d = q.front().second;
        q.pop();
        if(d <= K+1 && u == N+1)
            return true;
        if(d > K)
            continue;
        for(int i = 0; i < N+2; ++i) {
            if(!visit[i] && adj[u][i] <= limit) {
                visit[i] = true;
                q.push(pair<int, int>(i, d+1));
            }
        }
    }
    return false;
}

int run(int i, int j) {
    if(i >= j)
        return i;
    int m = (i+j)/2;
    if(bfs(m))
        return run(i, m);
    else
        return run(m+1, j);
}

int main() {
    scanf("%d %d", &N, &K);
    node.reserve(N+2);
    node.push_back(pair<int, int>(0, 0));
    int x, y;
    for(int i = 0; i < N; ++i) {
        scanf("%d %d", &x, &y);
        node.push_back(pair<int, int>(x, y));
    }
    node.push_back(pair<int, int>(10000, 10000));
    for(int i = 0; i < N+2; ++i) {
        for(int j = 0; j < N+2; ++j) {
            adj[i][j] = adj[j][i] = getFuel(node[i], node[j]);
        }
    }
    printf("%d\n", run(1, getFuel(node[0], node[N+1])));
    return 0;
}