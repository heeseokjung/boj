#include <stdio.h>
#include <vector>
#include <stack>
#include <set>
using namespace std;

int N, M, S, T;
vector<int> adj[10001];
int dfs_num[10001];
int dfs_low[10001];
bool visit[10001];
int scc_num[10001];
int scc[10001];
set<int> adj_scc[10001];
stack<int> s;
vector<int> sorted_order;
int dist[10001];
int dfs_count = 1, scc_count = 1;
#define INF -1

void input()
{
    scanf("%d %d %d %d", &N, &M, &S, &T);
    int u, v;
    for(int i = 0; i < M; ++i) {
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
    }
}

void tarjan(int x)
{
    dfs_low[x] = dfs_num[x] = dfs_count++;
    visit[x] = true;
    s.push(x);
    for(int i = 0; i < (int)adj[x].size(); ++i) {
        if(!dfs_num[adj[x][i]])
            tarjan(adj[x][i]);
        if(visit[adj[x][i]] && dfs_low[adj[x][i]] < dfs_low[x])
            dfs_low[x] = dfs_low[adj[x][i]];
    }
    if(dfs_num[x] == dfs_low[x]) {
        int top;
        while(true) {
            top = s.top();
            s.pop();
            visit[top] = false;
            scc_num[top] = scc_count;
            scc[scc_count]++;
            if(top == x)
                break;
        }
        scc_count++;
    }
}

void topological_sort(int x)
{
    visit[x] = true;
    for(auto it = adj_scc[x].begin(); it != adj_scc[x].end(); ++it) {
        if(!visit[*it])
            topological_sort(*it);
    }
    sorted_order.push_back(x);
}

void run()
{
    for(int i = 1; i <= N; ++i) {
        if(!dfs_num[i])
            tarjan(i);
    }

    for(int i = 1; i <= N; ++i) {
        for(int j = 0; j < (int)adj[i].size(); ++j) {
            if(scc_num[i] != scc_num[adj[i][j]])
                adj_scc[scc_num[i]].insert(scc_num[adj[i][j]]);
        }
        visit[i] = false;
        dist[i] = INF;
    }

    sorted_order.reserve(scc_count);
    for(int i = 1; i < scc_count; ++i) {
        if(!visit[i])
            topological_sort(i);
    }

    int pos = (int)sorted_order.size() - 1;
    while(sorted_order[pos] != scc_num[S])
        pos--;
    dist[sorted_order[pos]] = scc[sorted_order[pos]];
    while(pos >= 0) {
        int x = sorted_order[pos];
        for(auto it = adj_scc[x].begin(); it != adj_scc[x].end(); ++it) {
            if(dist[x] + scc[*it] > dist[*it])
                dist[*it] = dist[x] + scc[*it];
        }
        if(x == scc_num[T])
            break;
        --pos;
    }
    printf("%d\n", dist[scc_num[T]] == INF ? 0 : dist[scc_num[T]]);
}

int main()
{
    input();
    run();
}