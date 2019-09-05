#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int maze[1001];
vector<int> reachable[1001];
int dp[1001];
#define INF 1000000000

void input()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i)
        scanf("%d", &maze[i]);
}

void run()
{
    for(int i = 1; i < n; ++i) {
        for(int j = 1; j <= n && j <= i + maze[i]; ++j) {
            reachable[j].push_back(i);
        }
        dp[i] = INF;
    }

    dp[1] = 0;
    for(int i = 2; i <= n; ++i) {
        int prev_min = INF;
        for(int j = 0; j < (int)reachable[i].size(); ++j)
            prev_min = min(prev_min, dp[reachable[i][j]]);
        dp[i] = prev_min + 1;
    }
    printf("%d\n", dp[n] < INF ? dp[n] : -1);
}

int main()
{
    input();
    run();
    return 0;
}