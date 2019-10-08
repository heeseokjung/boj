#include <stdio.h>
#include <vector>
using namespace std;

vector<int> adj[1001];
int visit[1001];
int cycle = 0;

void dfs(int x)
{
    visit[x] = 1;
    for(int i = 0; i < (int)adj[x].size(); ++i) {
        if(visit[adj[x][i]] == 0)
            dfs(adj[x][i]);
        else if(visit[adj[x][i]] == 1)
            cycle++;
    }
    visit[x] = 2;
}

int main()
{
    int TC, N;
    scanf("%d", &TC);
    while(TC--) {
        scanf("%d", &N);
        int x;
        for(int i = 1; i <= N; ++i) {
            adj[i].clear();
            visit[i] = false;
        }
        for(int i = 1; i <= N; ++i) {
            scanf("%d", &x);
            adj[i].push_back(x);
        }
        for(int i = 1; i <= N; ++i) {
            if(!visit[i])
                dfs(i);
        }
        printf("%d\n", cycle);
        cycle = 0;
    }
    return 0;
}