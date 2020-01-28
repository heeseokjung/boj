#include <cstdio>
#include <algorithm>
using namespace std;

int N, P;
int cost[16][16];
int cache[70000];

int dfs(int status, int count) {
    if(cache[status] != -1) {
        return cache[status];
    }
    if(count >= P) {
        return 0;
    }
    int mn = 1e9;
    for(int j = 0; j < N; ++j) {
        if(!(status & (1 << j))) {
            for(int i = 0; i < N; ++i) {
                if(i == j)
                    continue;
                if(status & (1 << i))
                    mn = min(mn, dfs(status | (1 << j), count + 1) + cost[i][j]);
            }
        }
    }
    return cache[status] = mn;
}

int main() {
    scanf("%d", &N);
    for(int i = 0; i < N; ++i)
        for(int j = 0; j < N; ++j)
            scanf("%d", &cost[i][j]);
    getchar();
    int count = 0, status = 0;
    for(int i = 0; i < N; ++i) {
        char c;
        scanf("%c", &c);
        if(c == 'Y') {
            count++;
            status = status | (1 << i);
        }
    }
    getchar();
    scanf("%d", &P);

    for(int i = 0; i < (1 << N); ++i)
        cache[i] = -1;
    int ans = dfs(status, count);
    printf("%d\n", (ans == 1e9) ? -1 : ans);

    return 0;
}