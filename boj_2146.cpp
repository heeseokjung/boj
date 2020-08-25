#include <cstdio>
#include <utility>
#include <queue>
using namespace std;

int N;
int bfs_num = 0;
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};
int arr[100][100];
int visit1[100][100];
bool visit2[100][100];
pair<int, int> dist[100][100];

struct Node {
    int r, c, num, d;
};

void bfs1(int r, int c) {
    queue<pair<int, int> > q;
    visit1[r][c] = ++bfs_num;
    q.push({r, c});

    while(!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();
        int nr, nc;
        for(int i = 0; i < 4; ++i) {
            nr = p.first + dr[i];
            nc = p.second + dc[i];
            if(nr < 0 || nr > N-1 || nc < 0 || nc > N-1)
                continue;
            if(!visit1[nr][nc] && arr[nr][nc]) {
                visit1[nr][nc] = bfs_num;
                q.push({nr, nc});
            }
        }
    }
}

int main() {
    scanf("%d", &N);
    for(int i = 0; i < N; ++i)
        for(int j = 0; j < N; ++j)
            scanf("%d", &arr[i][j]);

    queue<struct Node> q;
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            if(!visit1[i][j] && arr[i][j]) {
                visit2[i][j] = true;
                q.push({i, j, bfs_num, 0});
                bfs1(i, j);
            }
        }
    }

    int min_d = 100;
    while(!q.empty()) {
        struct Node tmp = q.front();
        q.pop();
        int r = tmp.r;
        int c = tmp.c;
        int num = tmp.num;
        int d = tmp.d;
        q.pop();

        if(arr[r][c]) {
            int nr, nc;
            for(int i = 0; i < 4; ++i) {
                nr = r + dr[i];
                nc = c + dc[i];
                if(nr < 0 || nr > N-1 || nc < 0 || nc > N-1)
                    continue;
                if(!visit2[nr][nc]) {
                    visit2[nr][nc] = true;
                    if(arr[nr][nc]) {
                        q.push({nr, nc, num, d});
                    } else {
                        dist[nr][nc] = {d+1, num};
                        q.push({nr, nc, num, d+1});
                    }
                }
            }
        } else { 
            int nr, nc;
            for(int i = 0; i < 4; ++i) {
                nr = r + dr[i];
                nc = c + dc[i];
                if(nr < 0 || nr > N-1 || nc < 0 || nc > N-1)
                    continue;
                if(!visit2[nr][nc]) {
                    visit2[nr][nc] = true;
                    if(arr[nr][nc]) {
                        if(visit1[nr][nc] != d)
                            min_d = (min_d > d ? d : min_d);
                    } else {
                        dist[nr][nc] = {d+1, num};
                        q.push({nr, nc, num, d+1});
                    }
                } else {
                    if(arr[nr][nc] && visit1[nr][nc] != num)
                        min_d = (min_d > d ? d : min_d);
                    else if(!arr[nr][nc] && dist[nr][nc].second != num)
                        min_d = (min_d > dist[nr][nc].first + d ? dist[nr][nc].first + d : min_d);
                }
            }
            if(min_d == 1)
                printf("r: %d c: %d nr: %d nc: %d\n", r, c, nr, nc);
        }
    }

    printf("%d\n", min_d);

    printf("\n\n");
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            printf("%d ", visit1[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");

    printf("bfs_num: %d\n", bfs_num);
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            printf("%d ", dist[i][j].second);
        }
        printf("\n");
    }
    
    return 0;
}