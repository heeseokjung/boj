#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

int M, N;
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};
bool visit[1000][1000];
vector<string> arr;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> M >> N;
    arr = vector<string>(M);
    for(int i = 0; i < M; ++i)
        cin >> arr[i];

    queue<pair<int, int> > q;
    for(int i = 0; i < N; ++i) {
        if(arr[0][i] == '0') {
            visit[0][i] = true;
            q.push(pair<int, int>(0, i));
        }
    }

    while(!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();
        for(int i = 0; i < 4; ++i) {
            int nr = p.first + dr[i];
            int nc = p.second + dc[i];
            if(nr < 0 || nr > M-1 || nc < 0 || nc > N-1)
                continue;
            if(!visit[nr][nc] && arr[nr][nc] == '0') {
                visit[nr][nc] = true;
                q.push(pair<int, int>(nr, nc));
            }
        }
    }

    for(int i = 0; i < N; ++i) {
        if(visit[M-1][i]) {
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";

    return 0;
}