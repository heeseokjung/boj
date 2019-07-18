#include <stdio.h>
#include <utility>
#include <queue>
#include <algorithm>
using namespace std;

int n, k;
int coord[100001];
bool visit[3][100001] = {false, };
#define INF 1000000000

void input()
{
    scanf("%d %d", &n, &k);
}

void run()
{
    for(int i = 0; i < 100001; ++i)
        coord[i] = INF;

    queue<pair<int, pair<int, int> > > q;
    coord[n] = 0;
    q.push(make_pair(n, make_pair(coord[n], 0)));
    while(!q.empty()) {
        int x = q.front().first;
        int d = q.front().second.first;
        int t = q.front().second.second;
        q.pop();
        coord[x] = min(coord[x], d);
        if(visit[0][k] && visit[1][k] && visit[2][k])
            break;
        if(x + 1 <= 100000 && !visit[0][x+1] && x + 1 != n) {
            visit[0][x+1] = true;
            q.push(make_pair(x + 1, make_pair(d + 1, 0)));
        }
        if(x - 1 >= 0 && !visit[1][x-1] && x - 1 != n) {
            visit[1][x-1] = true;
            q.push(make_pair(x - 1, make_pair(d + 1, 1)));
        }
        if(x * 2 <= 100000 && !visit[2][x*2] && x * 2 != n) {
            visit[2][x*2] = true;
            q.push(make_pair(x * 2, make_pair(d + 1, 2)));
        }
    }

    printf("%d\n", coord[k]);
}

int main()
{
    input();
    run();
    return 0;
}