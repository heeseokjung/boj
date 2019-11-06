#include <stdio.h>
#include <utility>
#include <queue>
using namespace std;

int N;
pair<int, int> p1, p2;
int dr[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dc[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int dist[300][300];

int bfs() {
    if(p1 == p2)
        return 0;
    for(int i = 0; i < N; ++i)
        for(int j = 0; j < N; ++j)
            dist[i][j] = -1;
    queue<pair<int, int> > q;
    dist[p1.first][p1.second] = 0;
    q.push(p1);
    int r, c, nr, nc;
    while(!q.empty()) {
        r = q.front().first;
        c = q.front().second;
        q.pop();
        for(int i = 0; i < 8; ++i) {
            nr = r + dr[i];
            nc = c + dc[i];
            if(nr < 0 || nr >= N || nc < 0 || nc >= N)
                continue;
            if(dist[nr][nc] < 0) {
                dist[nr][nc] = dist[r][c] + 1;
                if(nr == p2.first && nc == p2.second)
                    return dist[nr][nc];
                else
                    q.push(pair<int, int>(nr, nc));
            }
        }
    }
}

int main() {
    int TC;
    scanf("%d", &TC);
    while(TC--) {
        scanf("%d", &N);
        scanf("%d %d", &p1.first, &p1.second);
        scanf("%d %d", &p2.first, &p2.second);
        printf("%d\n", bfs());
    }
    return 0;
}