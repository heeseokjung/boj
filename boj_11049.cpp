#include <cstdio>
#include <utility>
#include <algorithm>
using namespace std;

int N;
pair<int, int> matrix[500];
int cache[500][500];

int dp(int i, int j) {
    if(i == j)
        return 0;
    if(cache[i][j] != -1)
        return cache[i][j];
    int p = 2e9;
    for(int k = i; k < j; ++k)
        p = min(p, dp(i, k) + dp(k+1, j) + matrix[i].first * matrix[k].second * matrix[j].second);
    return cache[i][j] = p;
}

int main() {
    scanf("%d", &N);
    int x, y;
    for(int i = 0; i < N; ++i)
        scanf("%d %d", &matrix[i].first, &matrix[i].second);
    for(int i = 0; i < N; ++i)
        for(int j = 0; j < N; ++j)
            cache[i][j] = -1;
    printf("%d\n", dp(0, N-1));
    return 0;
}