#include <cstdio>
#include <vector>
using namespace std;

int N, M;
vector<int> adj[400];
vector<int> visit, match;

int dfs(int l) {
    if(visit[l])
        return 0;
    visit[l] = 1;
    for(int i = 0; i < (int)adj[l].size(); ++i) {
        int r = adj[l][i];
        if(match[r] == -1 || dfs(match[r])) {
            match[r] = l;
            return 1;
        }
    }
    return 0;
}

int main() {
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; ++i) {
        int size;
        scanf("%d", &size);
        for(int j = 0, k; j < size; ++j) {
            scanf("%d", &k);
            adj[i].push_back(k+N-1);
        }
    }

    int count = 0;
    match.assign(N+M, -1);
    for(int i = 0; i < N; ++i) {
        visit.assign(N, 0);
        count += dfs(i);
    }

    printf("%d\n", count);

    return 0;
}