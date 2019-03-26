// boj_11724

#include <stdio.h>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int Find(int* disjoint, int v);
void Union(int* disjoint, int v1, int v2);

int main()
{
    int v, e;
    scanf("%d %d", &v, &e);

    int disjoint[v+1];
    bool visit[v+1];
    for(int i = 1; i <= v; ++i) {
        disjoint[i] = 0;
        visit[i] = false;
    }

    vector<int> adj[v+1];
    for(int i = 0; i < e; ++i) {
        int start, end;
        scanf("%d %d", &start, &end);
        adj[start].push_back(end);
        adj[end].push_back(start);
    }

    // BFS for all vertex
    queue<int> q;
    for(int i = 1; i <= v; ++i) {
        q.push(i);
        while(!q.empty()) {
            int cur = q.front();
            for(int j = 0; j < adj[cur].size(); ++j) {
                if(!visit[adj[cur][j]]) {
                    visit[adj[cur][j]] = true;
                    q.push(adj[cur][j]);
                }
            }
            if(Find(disjoint, i) != Find(disjoint, cur))
                Union(disjoint, i, cur);
            q.pop();
        }
        for(int k = 1; k <= v; ++k)
            visit[k] = false;
    }

    // count connected components
    set<int> parent;
    for(int i = 1; i <= v; ++i) {
        if(disjoint[i] == 0)
            parent.insert(i);
        else {
            if(parent.find(Find(disjoint, i)) == parent.end())
                parent.insert(i);
        }
    }

    printf("%d\n", parent.size());

    return 0;
}

int Find(int* disjoint, int v)
{
    while(disjoint[v] > 0)
        v = disjoint[v];
    return v;
}

void Union(int* disjoint, int v1, int v2)
{
    if(Find(disjoint, v1) == Find(disjoint, v2))
        return;
    if(disjoint[v1] < disjoint[v2])
        disjoint[v2] = v1;
    else if(disjoint[v1] > disjoint[v2])
        disjoint[v1] = v2;
    else {
        disjoint[v2] = v1;
        disjoint[v1]--;
    }
}