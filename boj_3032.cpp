#include <cstdio>
#include <vector>
using namespace std;

int N;
int cache[100][100];
vector<int> v;

int dp(int i, int j) {
    if(i == j)
        return cache[i][j] = (v[i] % 2 ? 1 : 0);
    if(cache[i][j] != -1)
        return cache[i][j];
    int left = dp(i, i) - dp((i+1)%N, j);
    int right = dp(j, j) - dp(i, (j+N-1)%N);
    return cache[i][j] = max(left, right);
}

int main() {
    scanf("%d", &N);
    v = vector<int>(N);
    for(int i = 0; i < N; ++i)
        scanf("%d", &v[i]);
    for(int i = 0; i < N; ++i)
        for(int j = 0; j < N; ++j)
            cache[i][j] = -1;
    int count = 0;
    for(int i = 0; i < N; ++i) {
        if(dp(i, i) > dp((i+1)%N, (i+N-1)%N))
            count++;
    }
    printf("%d\n", count);
    return 0;
}