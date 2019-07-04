#include <stdio.h>
#include <queue>

using namespace std;

int n, m, x, y, k;
int map[20][20];
int dx[5] = {0, 0, 0, -1, 1};
int dy[5] = {0, 1, -1, 0, 0};
int top = 0, bottom = 0, north = 0, south = 0, west = 0, east = 0;
queue<int> cmd;

void input()
{
    scanf("%d %d %d %d %d", &n, &m, &x, &y, &k);
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            scanf("%d", &map[i][j]);
        }
    }
    int tmp;
    for(int i = 0; i < k; ++i) {
        scanf("%d", &tmp);
        cmd.push(tmp);
    }
}

void run()
{
    int nx, ny;
    while(!cmd.empty()) {
        int d = cmd.front();
        cmd.pop();
        nx = x + dx[d];
        ny = y + dy[d];
        if(nx < 0 || nx >= n || ny < 0 || ny >= m)
            continue;
        int tmp;
        switch(d) {
            case 1:    // E
                tmp = bottom;
                bottom = east;
                east = top;
                top = west;
                west = tmp;
                break;
            case 2:    // W
                tmp = bottom;
                bottom = west;
                west = top;
                top = east;
                east = tmp;
                break;
            case 3:    // N
                tmp = bottom;
                bottom = north;
                north = top;
                top = south;
                south = tmp;
                break;
            case 4:    // S
                tmp = bottom;
                bottom = south;
                south = top;
                top = north;
                north = tmp;
                break;
            default:
                break;
        }
        if(map[nx][ny] == 0) {
            map[nx][ny] = bottom;
        }
        else {
            bottom = map[nx][ny];
            map[nx][ny] = 0;
        }
        x = nx; y = ny;
        printf("%d\n", top);
    }
}

int main()
{
    input();
    run();
    
    return 0;
}