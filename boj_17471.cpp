#include <cstdio>
#include <vector>
using namespace std;

int N;
int total = 0, ans = (int)1e9;
int adj[11][11];
bool visit[11];
vector<int> v;

inline int absl(int x) {
    return (x < 0) ? -x : x;
}

inline void reset() {
    for(int i = 1; i <= N; ++i)
        visit[i] = false;
}

void dfs(int u, int mask) {
    visit[u] = true;
    for(int i = 1; i <= N; ++i) {
        if(adj[u][i]) {
            int v = i;
            if(!visit[v] && (mask & (1 << (v-1))))
                dfs(v, mask);
        }
    }
}

int main() {
    scanf("%d", &N);
    v = vector<int>(N);
    for(int i = 0; i < N; ++i) {
        scanf("%d", &v[i]);
        total += v[i];
    }
    for(int i = 0; i < N; ++i) {
        int x, v;
        scanf("%d", &x);
        for(int j = 0; j < x; ++j) {
            scanf("%d", &v);
            adj[i+1][v] = 1;
            adj[v][i+1] = 1;
        }
    }
    for(int j = 1; j < 1<<(N+1); ++j) {
        int dfs_count = 0;
        for(int i = 1; i <= N; ++i) {
            if(!visit[i] && (j & (1 << (i-1)))) {
                dfs_count++;
                dfs(i, j);
            }
        }
        if(dfs_count > 1) {
            reset();
            continue;
        }
        for(int i = 1; i <= N; ++i) {
            if(!visit[i]) {
                dfs_count++;
                dfs(i, (1<<(N+1)) - 1);
            }
        }
        if(dfs_count == 2) {
            int p = 1, k = 0;
            int sum = 0;
            while(p < j) {
                if(j & p)
                    sum += v[k];
                p = p << 1; k++;
            }
            int diff = absl(sum - (total - sum));
            ans = (diff < ans) ? diff : ans;
        }
        reset();
    }
    printf("%d\n", ans == (int)1e9 ? -1 : ans);
    return 0;
}