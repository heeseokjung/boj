#include <stdio.h>
#include <utility>
#include <vector>
#include <queue>
using namespace std;

int N, M, D;
int enemy_killed = 0, enemy_killed_max = 0;
int field[15][15];
int visit[15][15];
int dr[3] = {0, -1, 0}, dc[3] = {-1, 0, 1};
vector<pair<int, int> > enemy;

void attack(int r, int c, vector<pair<int, int> >& v) {
    visit[r][c] = 1;
    queue<pair<int, int> > q;
    q.push(pair<int, int>(r, c));
    pair<int, int> p;
    int nr, nc;
    while(!q.empty()) {
        p = q.front(); q.pop();
        if(visit[p.first][p.second] > D) {
            for(int i = 0; i <= r; ++i) {
                for(int j = 0; j < M; ++j)
                    visit[i][j] = 0;
            }
            return;
        }
        if(field[p.first][p.second]) {
            v.push_back(p);
            if(field[p.first][p.second]++ == 1)
                enemy_killed++;
            for(int i = 0; i <= r; ++i) {
                for(int j = 0; j < M; ++j)
                    visit[i][j] = 0;
            }
            return;
        }
        for(int i = 0; i < 3; ++i) {
            nr = p.first + dr[i];
            nc = p.second + dc[i];
            if(nr < 0 || nc < 0 || nc >= M)
                continue;
            if(!visit[nr][nc]) {
                visit[nr][nc] = visit[p.first][p.second] + 1;
                q.push(pair<int, int>(nr, nc));
            }
        }
    }
    for(int i = 0; i <= r; ++i) {
        for(int j = 0; j < M; ++j)
            visit[i][j] = 0;
    }
}

int main() {
    scanf("%d %d %d", &N, &M, &D);
    int e;
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < M; ++j) {
            scanf("%d", &e);
            if(e)
                enemy.push_back(pair<int, int>(i, j));
        }
    }
    for(int p = 0; p < M-2; ++p) {
        for(int q = p+1; q < M-1; ++q) {
            for(int r = q+1; r < M; ++r) {
                enemy_killed = 0;
                for(int i = 0; i < N; ++i) {
                    for(int j = 0; j < M; ++j)
                        field[i][j] = visit[i][j] = 0;
                }
                for(int i = 0; i < (int)enemy.size(); ++i)
                    field[enemy[i].first][enemy[i].second] = 1;
                vector<pair<int, int> > v;
                for(int i = N; i > 0; --i) {
                    attack(i-1, p, v);
                    attack(i-1, q, v);
                    attack(i-1, r, v);
                    for(int j = 0; j < (int)v.size(); ++j)
                        field[v[j].first][v[j].second] = 0;
                    v.clear();
                    for(int j = 0; j < M; ++j)
                        field[i-1][j] = 0;
                }
                if(enemy_killed > enemy_killed_max)
                    enemy_killed_max = enemy_killed;
            }
        }
    }
    printf("%d\n", enemy_killed_max);
    return 0;
}