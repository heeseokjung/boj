#include <cstdio>
#include <vector>
#include <set>

using namespace std;

#define INF 100000000
#define MIN(a, b) (((a) < (b)) ? (a) : (b))

int v, e;
int dfs_num[10001];
int dfs_min[10001];
int dfs_parent[10001];
int dfs_count = 0, is_root_articulation = 0;
vector<int> adj[10001];
set<int> articulation_point;

void dfs(int u, int root)
{
    dfs_num[u] = dfs_min[u] = dfs_count++;
    int v;
    for(int i = 0; i < adj[u].size(); ++i) {
        v = adj[u][i];
        if(dfs_num[v] == INF) {
            if(dfs_parent[u] < 0)
                is_root_articulation++;
            dfs_parent[v] = u;
            dfs(v, root);
            if(dfs_num[u] <= dfs_min[v] && u != root)
                articulation_point.insert(u);
            dfs_min[u] = min(dfs_min[u], dfs_min[v]);
        }
        else if(dfs_parent[u] != v)
            dfs_min[u] = min(dfs_min[u], dfs_num[v]);
    }
}

void run()
{
    for(int i = 1; i <= v; ++i) {
        if(dfs_num[i] == INF) {
            dfs(i, i);
            if(is_root_articulation >= 2)
                articulation_point.insert(i);
            is_root_articulation = 0;
        }
    }

    printf("%ld\n", articulation_point.size());
    for(set<int>::iterator it = articulation_point.begin(); it != articulation_point.end(); ++it)
        printf("%d ", *it);
    printf("\n");
}

int main()
{
    scanf("%d %d", &v, &e);
    int start, end;
    for(int i = 0; i < e; ++i) {
        scanf("%d %d", &start, &end);
        adj[start].push_back(end);
        adj[end].push_back(start);
    }
    for(int i = 1; i <= v; ++i) {
        dfs_num[i] = INF;
        dfs_min[i] = INF;
        dfs_parent[i] = -1;
    }

    run();

    return 0;
}
