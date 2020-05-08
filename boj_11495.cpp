#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, M;
int arr[50][50];
int m[50][50];
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};
int c[2510][2510];
int f[2510][2510];
const int inf = (int)1e9;

int main() {
    int TC;
    scanf("%d", &TC);
    while(TC--) {
        scanf("%d %d", &N, &M);
        int sum = 0;
        for(int i = 0; i < N; ++i) {
            for(int j = 0; j < M; ++j) {
                scanf("%d", &arr[i][j]);
                sum += arr[i][j];
            }
        }
        
        memset(c, 0, sizeof(c));
        memset(f, 0, sizeof(f));
        memset(m, 0, sizeof(m));

        vector<int> adj[2510];
        vector<int> v1, v2;
        int v1_count = 0, v2_count = 0;
        for(int i = 0; i < N; ++i) {
            for(int j = 0; j < M; ++j) {
                if((i+j)%2 == 0) {
                    v1.push_back(arr[i][j]);
                    m[i][j] = v1_count++;
                }
                else {
                    v2.push_back(arr[i][j]);
                    m[i][j] = v2_count++;
                }
            }
        }

        int pos = 1;
        for(int i = 0; i < (int)v1.size(); ++i) {
            c[0][pos] = v1[i];
            adj[0].push_back(pos);
            adj[pos].push_back(0);
            pos++;
        }
        for(int i = 0; i < (int)v2.size(); ++i) {
            c[pos][N*M+1] = v2[i];
            adj[pos].push_back(N*M+1);
            adj[N*M+1].push_back(pos);
            pos++;
        }

        for(int i = 0; i < N; ++i) {
            for(int j = 0; j < M; ++j) {
                if((i+j)%2 == 0) {
                    for(int k = 0; k < 4; ++k) {
                        int ii = i + dr[k];
                        int jj = j + dc[k];
                        if(ii < 0 || ii > N-1 || jj < 0 || jj > M-1)
                            continue;
                        int p1 = m[i][j] + 1;
                        int p2 = m[ii][jj] + (int)v1.size() + 1;
                        c[p1][p2] = inf;
                        adj[p1].push_back(p2);
                        adj[p2].push_back(p1);
                    }
                }
            }
        }

        int max_flow = 0;
        int prev[2510];
        while(true) {
            memset(prev, -1, sizeof(prev));
            queue<int> q;
            q.push(0);
            while(!q.empty()) {
                int u = q.front(); q.pop();
                for(int i = 0; i < (int)adj[u].size(); ++i) {
                    int v = adj[u][i];
                    if(c[u][v] > f[u][v] && prev[v] == -1) {
                        prev[v] = u;
                        if(v == N*M+1)
                            break;
                        q.push(v);
                    }
                }
            }

            if(prev[N*M+1] == -1)
                break;

            int min_capacity = inf;
            int p = N*M+1;
            while(p != 0) {
                min_capacity = min(min_capacity, c[prev[p]][p] - f[prev[p]][p]);
                p = prev[p];
            }

            p = N*M+1;
            while(p != 0) {
                f[p][prev[p]] -= min_capacity;
                f[prev[p]][p] += min_capacity;
                p = prev[p];
            }
            
            max_flow += min_capacity;
        }

        printf("%d\n", sum - max_flow);
    }
    return 0;
}