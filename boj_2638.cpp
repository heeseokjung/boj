#include <cstdio>
#include <utility>
#include <queue>
using namespace std;

int N, M;
int ans = 0;
int arr[100][100];
bool visit[100][100];
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

int main() {
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; ++i)
        for(int j = 0; j < M; ++j)
            scanf("%d", &arr[i][j]);

    queue<pair<pair<int, int>, int > > q;
    
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < M; ++j) {
            if(arr[i][j]) {
                int r, c, count = 0;
                for(int k = 0; k < 4; ++k) {
                    r = i + dr[k];
                    c = j + dc[k];
                    if(r < 0 || r > N-1 || c < 0 || c > M-1 || arr[r][c] == 0)
                        count++;
                }
                if(count >= 2) {
                    visit[i][j] = true;
                    ans = (ans < 1 ? 1 : ans);
                    q.push({{i, j}, 1});
                }
            }
        }
    }

    while(!q.empty()) {
        pair<int, int> p = q.front().first;
        int t = q.front().second;
        q.pop();

        arr[p.first][p.second] = 0;
        int r, c;
        for(int i = 0; i < 4; ++i) {
            r = p.first + dr[i];
            c = p.second + dc[i];
            if(arr[r][c] && !visit[r][c]) {
                int rr, cc, count = 0;
                for(int j = 0; j < 4; ++j) {
                    rr = r + dr[j];
                    cc = c + dc[j];
                    if(rr < 0 || rr > N-1 || cc < 0 || cc > M-1 || arr[rr][cc] == 0)
                        count++;
                }
                if(count >= 2) {
                    visit[r][c] = true;
                    ans = (ans < t+1 ? t+1 : ans);
                    q.push({{r, c}, t+1});
                }
            }
        }
    }

    printf("%d\n", ans);

    return 0;
}