#include <stdio.h>
#include <algorithm>
using namespace std;

int n, max_day = 1;
int forest[500][500];
int dp[500][500] = {0, };
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

void input()
{
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            scanf("%d", &forest[i][j]);
        }
    }
}

int dfs(int row, int col)
{
    int nr, nc;
    int day = 1;
    for(int i = 0; i < 4; ++i) {
        nr = row + dr[i];
        nc = col + dc[i];
        if(nr < 0 || nr >= n || nc < 0 || nc >= n)
            continue;
        if(forest[nr][nc] > forest[row][col]) {
            if(!dp[nr][nc])
                day = max(day, dfs(nr, nc) + 1);
            else
                day = max(day, dp[nr][nc] + 1);
        }
    }

    if(max_day < day)
        max_day = day;
        
    return dp[row][col] = day;
}

void run()
{
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            if(!dp[i][j])
                dfs(i, j);
        }
    }

    printf("%d\n", max_day);
}

int main()
{
    input();
    run();
    return 0;
}