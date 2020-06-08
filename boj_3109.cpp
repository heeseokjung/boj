#include <iostream>
#include <string>
using namespace std;

int R, C;
int dr[3] = {-1, 0, 1};
int dc[3] = {1, 1, 1};
int count = 0;
string arr[10000];
bool visit[10000][500];

bool move(int r, int c) {
    visit[r][c] = true;
    if(c == C-1) {
        count++;
        return true;
    }

    for(int i = 0; i < 3; ++i) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if(nr < 0 || nr > R-1 || arr[nr][nc] == 'x' || visit[nr][nc])
            continue;
        if(move(nr, nc))
            return true;
    }
    
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> R >> C;
    for(int i = 0; i < R; ++i)
        cin >> arr[i];

    for(int i = 0; i < R; ++i)
        move(i, 0);

    cout << count << "\n";

    return 0;
}