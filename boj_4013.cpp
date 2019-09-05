#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct Vertex
{
    int scc_num;
    bool current = false;
    int money;
    bool is_restaurant;
    vector<int> adj;
}Vertex;

typedef struct SCC
{
    int money = 0;
    bool is_restaurant = false;
    int sum = 0;
    vector<int> adj;
}SCC;

int N, M, S, P;
int dfs_count = 1, scc_count = 1;
int dfs_num[500001];
int dfs_low[500001];
vector<int> s;
vector<int> topological_order;
Vertex vertex[500001];
SCC scc[500001];

void input()
{
    scanf("%d %d", &N, &M);
    int x, y;
    for(int i = 0; i < M; ++i) {
        scanf("%d %d", &x, &y);
        vertex[x].adj.push_back(y);
    }
    for(int i = 1; i <= N; ++i)
        scanf("%d", &vertex[i].money);
    scanf("%d %d", &S, &P);
    int r;
    for(int i = 0; i < P; ++i) {
        scanf("%d", &r);
        vertex[r].is_restaurant = true;
    }
}

void tarjan(int x)
{
    dfs_low[x] = dfs_num[x] = dfs_count++;
    vertex[x].current = true;
    s.push_back(x);
    for(int i = 0; i < (int)vertex[x].adj.size(); ++i) {
        if(!dfs_num[vertex[x].adj[i]])
            tarjan(vertex[x].adj[i]);
        if(vertex[vertex[x].adj[i]].current)
            dfs_low[x] = min(dfs_low[x], dfs_low[vertex[x].adj[i]]);
    }
    int u;
    if(dfs_num[x] == dfs_low[x]) {
        topological_order.push_back(scc_count);
        while(true) {
            u = s.back();
            s.pop_back();
            vertex[u].scc_num = scc_count;
            vertex[u].current = false;
            scc[scc_count].money += vertex[u].money;
            scc[scc_count].is_restaurant |= vertex[u].is_restaurant;
            if(u == x)
                break;
        }
        scc_count++;
    }
}

void run()
{
    for(int i = 1; i <= N; ++i) {
        if(!dfs_num[i])
            tarjan(i);
    }

    for(int i = 1; i <= N; ++i) {
        for(int j = 0; j < (int)vertex[i].adj.size(); ++j) {
            if(vertex[i].scc_num != vertex[vertex[i].adj[j]].scc_num)
                scc[vertex[i].scc_num].adj.push_back(vertex[vertex[i].adj[j]].scc_num);
        }
    }

    int src;
    for(int i = (int)topological_order.size() - 1; i >= 0; --i) {
        if(topological_order[i] == vertex[S].scc_num) {
            src = i;
            break;
        }
    }
    scc[topological_order[src]].sum = scc[topological_order[src]].money;
    int max_sum = scc[topological_order[src]].sum;
    for(int i = src; i >= 0; --i) {
        int u = topological_order[i];
        for(int j = 0; j < (int)scc[u].adj.size(); ++j) {
            scc[scc[u].adj[j]].sum = max(scc[scc[u].adj[j]].sum, scc[u].sum + scc[scc[u].adj[j]].money);
            if(scc[scc[u].adj[j]].is_restaurant)
                max_sum = max(max_sum, scc[scc[u].adj[j]].sum);
        }
    }

    printf("%d\n", max_sum);
}

int main()
{
    input();
    run();
    return 0;
}