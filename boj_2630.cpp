#include <cstdio>
#include <utility>
#include <queue>
using namespace std;

int N;
int white = 0, blue = 0;
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};
int arr[128][128];
bool visit[128][128];

pair<int, int> bfs(int r, int c, int size) {
    for(int i = r; i < r+size; ++i)
        for(int j = c; j < c+size; ++j)
            visit[i][j] = false;

    int count = 0;
    for(int i = r; i < r+size; ++i) {
        for(int j = c; j < c+size; ++j) {
            if(!visit[i][j] && arr[i][j] == 1) {
                visit[i][j] = true;
                queue<pair<int, int> > q;
                q.push({i, j});
                while(!q.empty()) {
                    pair<int, int> p = q.front();
                    q.pop();
                    count++;
                    for(int k = 0; k < 4; ++k) {
                        int rr = p.first + dr[k];
                        int cc = p.second + dc[k];
                        if(rr < r || rr >= r+size || cc < c || cc >= c+size)
                            continue;
                        if(!visit[rr][cc] && arr[rr][cc] == 1) {
                            visit[rr][cc] = true;
                            q.push({rr, cc});
                        }
                    }
                }
            }
        }
    }

    return {count, size*size - count};
}

void divide(int r, int c, int size) {
    if(size == 0)
        return;

    pair<int, int> p = bfs(r, c, size);
    if(p.first == size*size) {
        blue++;
        return;
    } else if(p.second == size*size) {
        white++;
        return;
    } else {
        divide(r, c, size/2);
        divide(r, c + size/2, size/2);
        divide(r + size/2, c, size/2);
        divide(r + size/2, c + size/2, size/2);
    }
}

int main() {
    scanf("%d", &N);
    for(int i = 0; i < N; ++i)
        for(int j = 0; j < N; ++j)
            scanf("%d", &arr[i][j]);

    divide(0, 0, N);

    printf("%d\n%d\n", white, blue);

    return 0;
}