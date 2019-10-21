#include <cstdio>
#include <utility>
#include <queue>
using namespace std;

int N;
int color = 0, color_weak = 0;
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};
char arr[110][110];
bool visit[110][110];

void bfs(int r, int c, char k) {
    ++color;
    queue<pair<int, int> > q;
    visit[r][c] = true;
    q.push(pair<int, int>(r, c));
    int nr, nc;
    while(!q.empty()) {
        pair<int, int> p = q.front(); q.pop();
        for(int i = 0; i < 4; ++i) {
            nr = p.first + dr[i];
            nc = p.second + dc[i];
            if(nr < 0 || nr > N-1 || nc < 0 || nc > N-1)
                continue;
            if(!visit[nr][nc] && arr[nr][nc] == k) {
                visit[nr][nc] = true;
                q.push(pair<int, int>(nr, nc));
            }
        }
    }
}

void bfs_weak(int r, int c, char k) {
    ++color_weak;
    queue<pair<int, int> > q;
    visit[r][c] = true;
    q.push(pair<int, int>(r, c));
    int nr, nc;
    while(!q.empty()) {
        pair<int, int> p = q.front(); q.pop();
        for(int i = 0; i < 4; ++i) {
            nr = p.first + dr[i];
            nc = p.second + dc[i];
            if(nr < 0 || nr > N-1 || nc < 0 || nc > N-1)
                continue;
            if(!visit[nr][nc]) {
                if(arr[nr][nc] == k || (arr[nr][nc] == 'R' && arr[r][c] == 'G') || (arr[nr][nc] == 'G' && arr[r][c] == 'R')) {
                    visit[nr][nc] = true;
                    q.push(pair<int, int>(nr, nc));
                }
            }
        }
    }
}

int main() {
    scanf("%d", &N);
    getchar();
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j)
            scanf("%c", &arr[i][j]);
        getchar();
    }

    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            if(!visit[i][j])
                bfs(i, j, arr[i][j]);
        }
    }
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            visit[i][j] = false;
        }
    }
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            if(!visit[i][j])
                bfs_weak(i, j, arr[i][j]);
        }
    }
    printf("%d %d\n", color, color_weak);
    return 0;
}