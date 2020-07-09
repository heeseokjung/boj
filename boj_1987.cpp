#include <iostream>
#include <string>
#include <vector>
using namespace std;

int R, C;
int max_len = 0;
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};
bool visit[20][20];
string arr[20];

void dfs(vector<int>& path, int r, int c, int len) {
    visit[r][c] = true;
    path[arr[r][c]-'A'] = 1;
    for(int i = 0; i < 4; ++i) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if(nr < 0 || nr > R-1 || nc < 0 || nc > C-1)
            continue;
        if(!visit[nr][nc] && !path[arr[nr][nc]-'A'])
            dfs(path, nr, nc, len + 1);
    }
    if(max_len < len)
        max_len = len;
    path[arr[r][c]-'A'] = 0;
    visit[r][c] = false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> R >> C;
    for(int i = 0; i < R; ++i)
        cin >> arr[i];

    vector<int> path(26, 0);
    dfs(path, 0, 0, 1);

    cout << max_len << "\n";

    return 0;
}