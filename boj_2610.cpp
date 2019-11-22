#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int group_count = 0;
int dist[101][101];
bool visit[101];
vector<int> group[101];
#define INF 1000

int main() {
    scanf("%d %d", &N, &M);
    for(int i = 1; i <= N; ++i) {
        for(int j = 1; j <= N; ++j) {
            if(i == j)
                dist[i][j] = 0;
            else
                dist[i][j] = INF;
        }
    }
    int x, y;
    for(int i = 0; i < M; ++i) {
        scanf("%d %d", &x, &y);
        dist[x][y] = 1;
        dist[y][x] = 1;
    }
    for(int k = 1; k <= N; ++k) {
        for(int i = 1; i <= N; ++i) {
            for(int j = 1; j <= N; ++j) {
                if(dist[i][j] > dist[i][k] + dist[k][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
    for(int i = 1; i <= N; ++i) {
        if(!visit[i]) {
            visit[i] = true;
            group[++group_count].push_back(i);
            for(int j = 1; j <= N; ++j) {
                if(dist[i][j] != INF && !visit[j]) {
                    visit[j] = true;
                    group[group_count].push_back(j);
                }
            }
        }
    }
    vector<int> ans;
    for(int i = 1; i <= group_count; ++i) {
        int mn = 1000, mni;
        for(int j = 0; j < (int)group[i].size(); ++j) {
            int p = -1;
            for(int k = 0; k < (int)group[i].size(); ++k) {
                if(j == k)
                    continue;
                else if(p < dist[group[i][j]][group[i][k]])
                    p = dist[group[i][j]][group[i][k]];
            }
            if(p < mn) {
                mn = p;
                mni = group[i][j];
            }
        }
        ans.push_back(mni);
    }
    sort(ans.begin(), ans.end());
    printf("%d\n", group_count);
    for(int i = 0; i < (int)ans.size(); ++i)
        printf("%d\n", ans[i]);
    return 0;
}