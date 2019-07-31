#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int weight[10001];
vector<int> adj[10001];
int dp[2][10001] = {0, };
vector<int> ans;

void input()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i)
        scanf("%d", &weight[i]);
    int x, y;
    for(int i = 0; i < n - 1; ++i) {
        scanf("%d %d", &x, &y);
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
}

int dfs(int prev, int cur, int inc)
{
    if(dp[inc][cur])
        return dp[inc][cur];
    int sub = 0;
    for(int i = 0; i < (int)adj[cur].size(); ++i) {
        if(adj[cur][i] != prev) {
            if(inc)
                sub += dfs(cur, adj[cur][i], 0);
            else
                sub += max(dfs(cur, adj[cur][i], 0), dfs(cur, adj[cur][i], 1));
        }
    }
    if(inc) 
        return dp[inc][cur] = sub + weight[cur];
    else 
        return dp[inc][cur] = sub;
}

void get_mis(int prev, int cur, int inc)
{
    if(inc) {
        ans.push_back(cur);
        for(int i = 0; i < (int)adj[cur].size(); ++i) {
            if(adj[cur][i] != prev)
                get_mis(cur, adj[cur][i], 0);
        }
    }
    else {
        for(int i = 0; i < (int)adj[cur].size(); ++i) {
            if(adj[cur][i] != prev) {
                if(dp[1][adj[cur][i]] > dp[0][adj[cur][i]])
                    get_mis(cur, adj[cur][i], 1);
                else
                    get_mis(cur, adj[cur][i], 0);
            }
        }
    }
}

void run()
{   
    int mis = max(dfs(1, 1, 0), dfs(1, 1, 1));
    get_mis(1, 1, dp[0][1] < dp[1][1] ? 1 : 0);
    sort(ans.begin(), ans.end());

    
    printf("%d\n", mis);
    for(int i = 0; i < (int)ans.size(); ++i)
        printf("%d ", ans[i]);
    printf("\n");
}

int main()
{
    input();
    run();
    return 0;
}