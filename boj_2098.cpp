#include <stdio.h>
#include <algorithm>
using namespace std;

int N;
int adj[16][16];
int dp[16][1<<16] = {0, };
#define INF 1000000000

void input()
{
    scanf("%d", &N);
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            scanf("%d", &adj[i][j]);
        }
    }
}

int tsp(int p, int s)
{
    if(s == (1<<N) - 1) {
        return adj[p][0] ? adj[p][0] : INF;
    }
    if(dp[p][s]) {
        return dp[p][s];
    }
    int result = INF;
    for(int i = 0; i < 16; ++i) {
        if(i == p)
            continue;
        if(adj[p][i] && !(s & (1 << i)))
            result = min(result, adj[p][i] + tsp(i, s | (1 << i)));
    }
    return dp[p][s] = result;
}

void run()
{
    printf("%d\n", tsp(0, 1));
}

int main()
{
    input();
    run();
    return 0;
}