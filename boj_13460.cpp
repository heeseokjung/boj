#include <stdio.h>
#include <utility>
#include <queue>

using namespace std;

int n, m;
char board[10][10];
pair<int, int> RED, BLUE;
int min_depth = 11;
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

void input()
{
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; ++i) {
        scanf("%s", board[i]);
        for(int j = 0; j < m; ++j) {
            if(board[i][j] == 'R')
                RED = make_pair(i, j);
            else if(board[i][j] == 'B')
                BLUE = make_pair(i, j);
        }
    }
}

int get_ban_direction(int prev)
{
    if(prev == 0)
        return 1;
    else if(prev == 1)
        return 0;
    else if(prev == 2)
        return 3;
    else if(prev == 3)
        return 2;
    else 
        return prev;
}

void dfs(pair<int, int> red, pair<int, int> blue, int depth, int prev)
{
    if(depth > 10)
        return;
    int ban = get_ban_direction(prev);
    int rr, rc, br, bc;
    bool whole_red, whole_blue;
    for(int i = 0; i < 4; ++i) {
        if(i == ban)
            continue;
        rr = red.first, rc = red.second;
        br = blue.first, bc = blue.second;
        whole_red = false, whole_blue = false;
        while(board[rr+dr[i]][rc+dc[i]] != '#' && !(rr+dr[i] == br && rc+dc[i] == bc)) {
            rr += dr[i]; rc += dc[i];
            if(board[rr][rc] == 'O')
                whole_red = true;
        }
        while(board[br+dr[i]][bc+dc[i]] != '#' && !(br+dr[i] == rr && bc+dc[i] == rc)) {
            br += dr[i]; bc += dc[i];
            if(board[br][bc] == 'O')
                whole_blue = true;
        }
        while(board[rr+dr[i]][rc+dc[i]] != '#' && !(rr+dr[i] == br && rc+dc[i] == bc)) {
            rr += dr[i]; rc += dc[i];
            if(board[rr][rc] == 'O')
                whole_red = true;
        }
        if(rr == red.first && rc == red.second && br == blue.first && bc == blue.second) {
            continue;
        }
        if(board[rr][rc] == 'O') {
            while(board[br+dr[i]][bc+dc[i]] != '#') {
                br += dr[i]; bc += dc[i];
                if(board[br][bc] == 'O')
                    whole_blue = true;
            }
        }
        if(board[br][bc] == 'O') {
            while(board[rr+dr[i]][rc+dc[i]] != '#') {
                rr += dr[i]; rc += dc[i];
                if(board[rr][rc] == 'O')
                    whole_red = true;
            }
        }
        if(whole_blue) {
            continue;
        }
        if(whole_red) {
            min_depth = (depth + 1 < min_depth) ? depth + 1 : min_depth;
            return;
        }
        dfs(make_pair(rr, rc), make_pair(br, bc), depth + 1, i);
    }
}

void run()
{
    dfs(RED, BLUE, 0, -1);

    if(min_depth > 10)
        printf("-1\n");
    else
        printf("%d\n", min_depth);
}

int main()
{
    input();
    run();

    return 0;
}