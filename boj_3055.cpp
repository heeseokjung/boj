#include <iostream>
#include <utility>
#include <string>
#include <queue>
using namespace std;
#include <cstdio>

int R, C;
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};
char arr[50][50];
int dist[50][50];
int water[50][50];
bool visit[50][50];
pair<int, int> s, e;

void bfs() {
    for(int i = 0; i < R; ++i) {
        for(int j = 0; j < C; ++j) {
            visit[i][j] = false;
            water[i][j] = (int)1e9;
        }
    }
    queue<pair<int, int> > q;
    for(int i = 0; i < R; ++i) {
        for(int j = 0; j < C; ++j) {
            if(arr[i][j] == '*') {
                visit[i][j] = true;
                water[i][j] = 0;
                q.push(pair<int, int>(i, j));
            }
        }
    }
    while(!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        for(int i = 0; i < 4; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr < 0 || nr >= R || nc < 0 || nc >= C)
                continue;
            if(!visit[nr][nc] && (arr[nr][nc] == '.' || arr[nr][nc] == 'S')) {
                visit[nr][nc] = true;
                water[nr][nc] = water[r][c] + 1;
                q.push(pair<int, int>(nr, nc));
            }
        }
    }
}

int find() {
    for(int i = 0; i < R; ++i) 
        for(int j = 0; j < C; ++j)
            visit[i][j] = false;
    queue<pair<int, int> > q;
    visit[s.first][s.second] = true;
    q.push(s);
    while(!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        for(int i = 0; i < 4; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr < 0 || nr >= R || nc < 0 || nc >= C)
                continue;
            if(!visit[nr][nc] && (arr[nr][nc] == '.' || arr[nr][nc] == 'D') &&
               dist[r][c] + 1 < water[nr][nc]) {
                visit[nr][nc] = true;
                dist[nr][nc] = dist[r][c] + 1;
                if(nr == e.first && nc == e.second)
                    return dist[nr][nc];
                q.push(pair<int, int>(nr, nc));
            }
        }
    }
    return -1;
}

int main() {
    cin >> R >> C;
    for(int i = 0; i < R; ++i) {
        string line;
        cin >> line;
        for(int j = 0; j < (int)line.size(); ++j) {
            arr[i][j] = line[j];
            if(arr[i][j] == 'S')
                s = pair<int, int>(i, j);
            else if(arr[i][j] == 'D')
                e = pair<int, int>(i, j);
        }
    }
    bfs();
    int ans = find();
    if(ans == -1)
        cout << "KAKTUS" << "\n";
    else
        cout << ans << "\n";
    return 0;
}