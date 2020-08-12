#include <cstdio>
#include <utility>
#include <queue>
using namespace std;

int N, M;
int ans = 0;
int arr[100][100];
bool air[100][100];
bool visit[100][100];
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

void find_air(pair<int, int> p) {
    queue<pair<int, int> > q;
    air[p.first][p.second] = true;
    q.push(p);
    while(!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        for(int i = 0; i < 4; ++i) {
            int rr = r + dr[i];
            int cc = c + dc[i];
            if(rr < 0 || rr > N-1 || cc < 0 || cc > M-1)
                continue;
            if(!air[rr][cc] && arr[rr][cc] == 0) {
                air[rr][cc] = true;
                q.push({rr, cc});
            }
        }
    }
}

int main() {
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; ++i)
        for(int j = 0; j < M; ++j)
            scanf("%d", &arr[i][j]);

    find_air({0, 0});

    queue<pair<pair<int, int>, int> > q;

    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < M; ++j) {
            if(arr[i][j]) {
                int count = 0;
                for(int k = 0; k < 4; ++k) {
                    int ii = i + dr[k];
                    int jj = j + dc[k];
                    if(ii < 0 || ii > N-1 || jj < 0 || jj > M-1)
                        continue;
                    if(air[ii][jj])
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
        find_air(p);

        for(int i = 0; i < N; ++i) {
            for(int j = 0; j < M; ++j) {
                if(!visit[i][j] && arr[i][j]) {
                    int count = 0;
                    for(int k = 0; k < 4; ++k) {
                        int ii = i + dr[k];
                        int jj = j + dc[k];
                        if(ii < 0 || ii > N-1 || jj < 0 || jj > M-1)
                            continue;
                        if(air[ii][jj])
                            count++;
                    }
                    if(count >= 2) {
                        visit[i][j] = true;
                        ans = (ans < t+1 ? t+1 : ans);
                        q.push({{i, j}, t+1});
                    }
                }
            }
        }
    }

    printf("%d\n", ans);

    return 0;
}