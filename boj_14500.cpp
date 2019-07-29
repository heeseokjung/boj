#include <stdio.h>

int n, m, max_sum = -1;
int arr[501][501];
bool visit[501][501];
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};
int edge_dr[4][3] = {{-1, 1, 0}, {-1, 1, 0}, {0, 0, -1}, {0, 0, 1}};
int edge_dc[4][3] = {{0, 0, 1}, {0, 0, -1}, {-1, 1, 0}, {-1, 1, 0}};

void input()
{
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            scanf("%d", &arr[i][j]);
        }
    }
}

void dfs(int r, int c, int d, int s)
{
    if(d == 4) {
        if(s > max_sum)
            max_sum = s;
        visit[r][c] = false;
        return;
    }
    int nr, nc;
    for(int i = 0; i < 4; ++i) {
        nr = r + dr[i];
        nc = c + dc[i];
        if(nr < 1 || nr > n || nc < 1 || nc > m)
            continue;
        if(!visit[nr][nc]) {
            visit[nr][nc] = true;
            dfs(nr, nc, d + 1, s + arr[nr][nc]);
        }
    }
    visit[r][c] = false;
}

void edge_case(int r, int c)
{
    int nr, nc;
    for(int i = 0; i < 4; ++i) {
        int sum = arr[r][c];
        int count = 1;
        for(int j = 0; j < 3; ++j) {
            nr = r + edge_dr[i][j];
            nc = c + edge_dc[i][j];
            if(nr < 1 || nr > n || nc < 1 || nc > m)
                break;
            sum += arr[nr][nc];
            count++;
        }
        if(count == 4 && max_sum < sum)
            max_sum = sum;
    }
}

void run()
{
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            visit[i][j] = true;
            dfs(i, j, 1, arr[i][j]);
            edge_case(i, j);
        }
    }

    printf("%d\n", max_sum);
}

int main()
{
    input();
    run();
    return 0;
}