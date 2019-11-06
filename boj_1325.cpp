#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;

int N, M;
int max_size = -1;
bool visit[10001];
int size[10001];
vector<int> adj[10001];

void dfs(int x) {
    visit[x] = true;
    if(++size[x] > max_size)
        max_size = size[x];
    for(int i = 0; i < (int)adj[x].size(); ++i) {
        if(!visit[adj[x][i]]) 
            dfs(adj[x][i]);
    }
}

int main() {
    scanf("%d %d", &N, &M);
    int x, y;
    for(int i = 0; i < M; ++i) {
        scanf("%d %d", &x, &y);
        adj[x].push_back(y);
    }
    for(int i = 1; i <= N; ++i) {
        memset(visit, false, sizeof(bool)*(N+1));
        dfs(i);
    }
    for(int i = 1; i <= N; ++i) {
        if(size[i] == max_size)
            printf("%d ", i);
    }
    printf("\n");
    return 0;
}