#include <stdio.h>
#include <utility>
#include <queue>
#include <algorithm>
using namespace std;

int N, M;
int map[1001][1001];
int dist[1001][1001][2] = {0, };
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};
char buf[1001];
int min_dist = -1;
typedef struct Node
{
    pair<int, int> p;
    int is_broked;
}Node;

void input()
{
    scanf("%d %d", &N, &M);
    getchar();
    for(int i = 1; i <= N; ++i) {
        fgets(buf, sizeof(buf), stdin);
        for(int j = 0; j < M; ++j)
            map[i][j+1] = buf[j] - '0';
    }
}

void run()
{
    queue<Node> q;
    q.push(Node{pair<int, int>(1, 1), 0});
    dist[1][1][0] = 1;
    int r, c;
    while(!q.empty()) {
        Node n = q.front(); q.pop();
        r = n.p.first; c = n.p.second;
        if(r == N && c == M) {
            min_dist = dist[r][c][n.is_broked];
            break;
        }
        int nr, nc;
        for(int i = 0; i < 4; ++i) {
            nr = r + dr[i]; nc = c + dc[i];
            if(nr < 1 || nr > N || nc < 1 || nc > M)
                continue;
            if(!dist[nr][nc][n.is_broked] && map[nr][nc] == 0) {
                dist[nr][nc][n.is_broked] = dist[r][c][n.is_broked] + 1;
                q.push(Node{pair<int, int>(nr, nc), n.is_broked});
            }
            if(!dist[nr][nc][1] && map[nr][nc] == 1 && !n.is_broked) {
                dist[nr][nc][1] = dist[r][c][n.is_broked] + 1;
                q.push(Node{pair<int, int>(nr, nc), 1});
            }
        }
    }

    printf("%d\n", min_dist);
}

int main()
{
    input();
    run();
    return 0;
}