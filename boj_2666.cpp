#include <cstdio>
#include <algorithm>
using namespace std;

int N, M;
int order[21];
int cache[21][21][21];

inline int absl(int x) {
    return (x < 0) ? -x : x;
}

int dp(int pos, int x, int y) {
    if(pos >= M)
        return 0;
    if(cache[pos][x][y] != -1)
        return cache[pos][x][y];
    return cache[pos][x][y] = min(
        absl(order[pos]-x) + dp(pos+1, order[pos], y),
        absl(order[pos]-y) + dp(pos+1, x, order[pos])
    );
}

int main() {
    scanf("%d", &N);
    int x, y;
    scanf("%d %d", &x, &y);
    scanf("%d", &M);
    for(int i = 0; i < M; ++i)
        scanf("%d", order+i);
    for(int i = 0; i < M; ++i)
        for(int j = 1; j <= N; ++j)
            for(int k = 1; k <= N; ++k)
                cache[i][j][k] = -1;
    printf("%d\n", dp(0, x, y));
    return 0;
}