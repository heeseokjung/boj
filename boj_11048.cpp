#include <cstdio>
#include <algorithm>
using namespace std;

int N, M;
int arr[1000][1000];
int cache[1000][1000];

int dp(int i, int j) {
    if(i == 0 && j == 0)
        return cache[i][j] = arr[i][j];
    if(cache[i][j] != -1)
        return cache[i][j];
    int a = 0, b = 0, c = 0;
    if(i > 0)
        a += dp(i-1, j);
    if(j > 0)
        b += dp(i, j-1);
    if(i > 0 && j > 0)
        c += dp(i-1, j-1);
    return cache[i][j] = max(max(a, b), c) + arr[i][j]; 
}

int main() {
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < M; ++j) {
            scanf("%d", &arr[i][j]);
            cache[i][j] = -1;
        }
    }
    printf("%d\n", dp(N-1, M-1));
    return 0;
}