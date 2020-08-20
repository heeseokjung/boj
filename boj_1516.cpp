#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int time[501];
int indegree[501];
int visit[501];
int dp[501];
vector<int> adj[501];

void dfs(int u, vector<int>& s) {
    visit[u] = 1;
    for(int i = 0; i < (int)adj[u].size(); ++i) {
        int v = adj[u][i];
        if(!visit[v])
            dfs(v, s);
    }
    s.push_back(u);
}

int main() {
    scanf("%d", &N);
    for(int i = 1; i <= N; ++i) {
        scanf("%d", &time[i]);
        int j;
        while(true) {
            scanf("%d", &j);
            if(j == -1)
                break;
            adj[j].push_back(i);
            indegree[i]++;
        }
    }

    for(int i = 1; i <= N; ++i) {
        if(!indegree[i] && !visit[i]) {
            vector<int> s;
            dfs(i, s);
            reverse(s.begin(), s.end());

            for(int j = 0; j < (int)s.size(); ++j) {
                int u = s[j];
                dp[u] = (dp[u] < time[u] ? time[u] : dp[u]);
                for(int k = 0; k < (int)adj[u].size(); ++k) {
                    int v = adj[u][k];
                    if(dp[u] + time[v] > dp[v])
                        dp[v] = dp[u] + time[v];
                }
            }
        }
    }

    for(int i = 1; i <= N; ++i)
        printf("%d\n", dp[i]);

    return 0;
}