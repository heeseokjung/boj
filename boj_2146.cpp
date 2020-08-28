#include <cstdio>
#include <tuple>
#include <queue>
using namespace std;

int N;
int dfs_num = 0, min_dist = (int)1e9;
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};
int arr[100][100];
int visit[100][100];
int dist[100][100];
// r, c, dfs_num, dist
queue<tuple<int, int, int, int> > q;

void dfs(int r, int c) {
    visit[r][c] = dfs_num;
    for(int i = 0; i < 4; ++i) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if(nr < 0 || nr > N-1 || nc < 0 || nc > N-1) {
            continue;
        }
        if(!visit[nr][nc] && arr[nr][nc]) {
            dfs(nr, nc);
        }
        if(!visit[nr][nc] && !arr[nr][nc]) {
            visit[nr][nc] = -dfs_num;
            dist[nr][nc] = 1;
            q.push(make_tuple(nr, nc, dfs_num, 1));
        }
    }
}

void bfs() {
    while(!q.empty()) {
        int r, c, id, d;
        tie(r, c, id, d) = q.front(); q.pop();
        for(int i = 0; i < 4; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr < 0 || nr > N-1 || nc < 0 || nc > N-1) {
                continue;
            }
            if(visit[nr][nc]) {
                if(arr[nr][nc] && visit[nr][nc] != id)
                    min_dist = (min_dist > d ? d : min_dist);
                else if(!arr[nr][nc] && -visit[nr][nc] != id)
                    min_dist = (min_dist > dist[nr][nc] + d ? dist[nr][nc] + d : min_dist);
            } else if(!arr[nr][nc]) {
                visit[nr][nc] = -id;
                dist[nr][nc] = d+1;
                q.push(make_tuple(nr, nc, id, d+1));
            }
        }
    }
}

int main() {
    scanf("%d", &N);
    for(int i = 0; i < N; ++i)
        for(int j = 0; j < N; ++j)
            scanf("%d", &arr[i][j]);

    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            if(!visit[i][j] && arr[i][j]) {
                dfs_num++;
                dfs(i, j);
            }
        }
    }

    bfs();

    printf("%d\n", min_dist);
   
    return 0;
}