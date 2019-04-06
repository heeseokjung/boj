// boj_2150

#include <stdio.h>
#include <string.h>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

#define UNVISIT -1
#define MIN(a, b) (((a) < (b)) ? (a) : (b))

int num_v, num_e;
int dfs_count = 0;
int dfs_num[10001];
int dfs_min[10001];
bool visit[10001];
vector<int> adj[10001];
typedef vector<int> SCC;
stack<int> s;
vector<SCC> scc;

void dfs(int u)
{
    dfs_min[u] = dfs_num[u] = dfs_count++;
    s.push(u);
    visit[u] = true;
    for(int i = 0; i < adj[u].size(); ++i) {
        int v = adj[u][i];
        if(dfs_num[v] == UNVISIT)
            dfs(v);
        if(visit[v])
            dfs_min[u] = MIN(dfs_min[u], dfs_min[v]);
    }
    if(dfs_num[u] == dfs_min[u]) {
        SCC tmp;
        while(1) {
            int top = s.top();
            visit[top] = false;
            tmp.push_back(top);
            s.pop();
            if(dfs_num[top] == dfs_min[top])
                break;
        }
        sort(tmp.begin(), tmp.end());
        scc.push_back(tmp);
    }
}

void run()
{
    for(int i = 1; i <= num_v; ++i) {
        if(dfs_num[i] == UNVISIT)
            dfs(i);
    }

    printf("%ld\n", scc.size());
    sort(scc.begin(), scc.end());
    for(int i = 0; i < scc.size(); ++i) {
        for(int j = 0; j < scc[i].size(); ++j)
            printf("%d ", scc[i][j]);
        printf("%d\n", -1);
    }
}

int main()
{
    scanf("%d %d", &num_v, &num_e);
    for(int i = 0; i < num_e; ++i) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
    }
    memset(dfs_num, UNVISIT, sizeof(int) * (num_v + 1));
    memset(dfs_min, UNVISIT, sizeof(int) * (num_v + 1));
    memset(visit, false, sizeof(bool) * (num_v + 1));

    run();

    return 0;
}