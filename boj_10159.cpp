#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int adj[101][101];
vector<int> ans;

void input()
{
    scanf("%d %d", &n, &m);
    int x, y;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            if(i == j)
                adj[i][j] = 1;
            else
                adj[i][j] = 0;
        }
    }
    for(int i = 0; i < m; ++i) {
        scanf("%d %d", &x, &y);
        adj[y][x] = 1;
    }
}

void run()
{   
    for(int k = 1; k <= n; ++k) {
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= n; ++j) {
                if(adj[i][k] && adj[k][j])
                    adj[i][j] = 1;
            }
        }
    }

    for(int i = 1; i <= n; ++i) {
        int count = 0;
        for(int j = 1; j <= n; ++j) {
            if(i == j)
                continue;
            if(!adj[i][j] && !adj[j][i])
                count++;
        }
        ans.push_back(count);
    }

    for(int i = 0; i < (int)ans.size(); ++i)
        printf("%d\n", ans[i]);
}

int main() 
{
    input();
    run();

    return 0;
}