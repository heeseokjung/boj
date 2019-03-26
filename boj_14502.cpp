// boj_14502

#include <stdio.h>

#define BLANK 0
#define WALL 1
#define VIRUS 2

int map[9][9];

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j)
            scanf("%d", &map[i][j]);
    }



    return 0;
}