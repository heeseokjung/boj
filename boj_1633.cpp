#include <stdio.h>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int> > player;
int N;
int memo[1000][16][16];

void input()
{
    player.reserve(30);
    int x, y;
    while(scanf("%d %d", &x, &y) != EOF) 
        player.push_back(pair<int, int>(x, y));
    N = (int)player.size();
}

int dp(int pos, int black, int white)
{
    if(pos == N)
        return 0;
    if(memo[pos][black][white] != -1)
        return memo[pos][black][white];
    int mx = dp(pos + 1, black, white);
    if(black > 0)
        mx = max(mx, dp(pos + 1, black - 1, white) + player[pos].second);
    if(white > 0)
        mx = max(mx, dp(pos + 1, black, white - 1) + player[pos].first);
    return memo[pos][black][white] = mx;
}

void run()
{
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < 16; ++j) {
            for(int k = 0; k < 16; ++k) {
                memo[i][j][k] = -1;
            }
        }
    }

    printf("%d\n", dp(0, 15, 15));
}

int main()
{
    input();
    run();
    return 0;
}