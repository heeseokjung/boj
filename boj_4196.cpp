// boj_4196

#include <stdio.h>
#include <string.h>
#include <vector>
#include <stack>

using namespace std;

#define UNVISIT -1
#define MIN(a, b) (((a) < (b)) ? (a) : (b))

int num_v, num_e;
int dfs_count = 0, scc_count = 0;
int dfs_num[100001];
int dfs_min[100001];
int scc[100001];
int indegree[100001];
bool visit[100001];
vector<int> adj[100001];
stack<int> s;

void dfs(int u) 
{
    dfs_min[u] = dfs_num[u] = dfs_count++;
    visit[u] = true;
    s.push(u);
    for(int i = 0; i < adj[u].size(); ++i) {
        int v = adj[u][i];
        if(dfs_num[v] == UNVISIT)
            dfs(v);
        if(visit[v])
            dfs_min[u] = MIN(dfs_min[u], dfs_min[v]);
    }
    if(dfs_num[u] == dfs_min[u]) {
        scc_count++;
        while(1) {
            int top = s.top();
            s.pop();
            visit[top] = false;
            scc[top] = scc_count;
            if(dfs_num[top] == dfs_min[top])
                break;
        }
    }
}

void run()
{
    for(int i = 1; i <= num_v; ++i) {
        if(dfs_num[i] == UNVISIT)
            dfs(i);
    }

    int indegree[scc_count + 1] = {0, };
    for(int u = 1; u <= num_v; ++u) {
        for(int i = 0; i < adj[u].size(); ++i) {
            int v = adj[u][i];
            if(scc[u] != scc[v])
                indegree[scc[v]]++;
        }
    }
    int count = 0;
    for(int i = 1; i <= scc_count; ++i) {
        if(indegree[i] == 0)
            count++;
    }
    

    printf("%d\n", count);
    dfs_count = 0;
    scc_count = 0;
    while(!s.empty())
        s.pop();
}

int main()
{   
    int num_test_case;
    scanf("%d", &num_test_case);
    for(int i = 0; i < num_test_case; ++i) {
        scanf("%d %d", &num_v, &num_e);
        memset(dfs_num, UNVISIT, sizeof(int) * (num_v + 1));
        memset(dfs_min, UNVISIT, sizeof(int) * (num_v + 1));
        memset(visit, false, sizeof(bool) * (num_v + 1));
        for(int j = 0; j < num_e; ++j) {
            int u, v;
            scanf("%d %d", &u, &v);
            adj[u].push_back(v);
        }

        run();

        for(int i = 1; i <= num_v; ++i)
            adj[i].clear();
    }
}