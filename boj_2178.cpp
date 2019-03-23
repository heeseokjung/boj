// boj_2178

#include <stdio.h>
#include <utility>
#include <queue>

using namespace std;

#define WHITE 1
#define GRAY 2
#define BLACK 3

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    int adj[n+1][m+1];
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j)
            scanf("%1d", &adj[i][j]);
    }

    int dist[n+1][m+1];
    // init
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j)
            dist[i][j] = 0;
    }

    // BFS
    queue<pair<int, int> > q;
    q.push(make_pair(1, 1));

    while(adj[n][m] != BLACK) {
        pair<int, int> p = q.front();
        if(p.first > 1 && adj[p.first-1][p.second] == WHITE) {
            q.push(make_pair(p.first-1, p.second));
            adj[p.first-1][p.second] = GRAY;
            dist[p.first-1][p.second] = dist[p.first][p.second] + 1;
        }
        if(p.first < n && adj[p.first+1][p.second] == WHITE) {
            q.push(make_pair(p.first+1, p.second));
            adj[p.first+1][p.second] = GRAY;
            dist[p.first+1][p.second] = dist[p.first][p.second] + 1;
        }
        if(p.second > 1 && adj[p.first][p.second-1] == WHITE) {
            q.push(make_pair(p.first, p.second-1));
            adj[p.first][p.second-1] = GRAY;
            dist[p.first][p.second-1] = dist[p.first][p.second] + 1;
        }
        if(p.second < m && adj[p.first][p.second+1] == WHITE) {
            q.push(make_pair(p.first, p.second+1));
            adj[p.first][p.second+1] = GRAY;
            dist[p.first][p.second+1] = dist[p.first][p.second] + 1;
        }
        adj[p.first][p.second] = BLACK;
        q.pop();
    }

    printf("%d\n", dist[n][m] + 1); // <1, 1> => 1

    return 0;
}