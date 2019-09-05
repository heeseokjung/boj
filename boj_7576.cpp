#include <stdio.h>
#include <utility>
#include <queue>

using namespace std;

int main()
{
    int m, n;
    scanf("%d %d", &m, &n);
    
    int tomato[n+1][m+1];
    int num_unripe = 0;
    queue<pair<int, int> > q;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            scanf("%d", &tomato[i][j]);
            if(tomato[i][j] == 1)
                q.push(make_pair(i, j));
            else if(tomato[i][j] == 0)
                num_unripe++;
        }
    }

    if(num_unripe == 0) { // all ripen
        printf("%d\n", 0);
        return 0;
    }

    if(q.empty()) { // no ripen 
        printf("%d\n", -1);
        return 0;
    }

    int day = 0;
    while(!q.empty()) {
        pair<int, int> p = q.front();
        int count = q.size();
        for(int i = 0; i < count; ++i) {
            pair<int, int> p = q.front();
            if(p.first > 1 && tomato[p.first-1][p.second] == 0) {
                q.push(make_pair(p.first-1, p.second));
                tomato[p.first-1][p.second] = 1;
                num_unripe--;
            }
            if(p.first < n && tomato[p.first+1][p.second] == 0) {
                q.push(make_pair(p.first+1, p.second));
                tomato[p.first+1][p.second] = 1;
                num_unripe--;
            }
            if(p.second > 1 && tomato[p.first][p.second-1] == 0) {
                q.push(make_pair(p.first, p.second-1));
                tomato[p.first][p.second-1] = 1;
                num_unripe--;
            }
            if(p.second < m && tomato[p.first][p.second+1] == 0) {
                q.push(make_pair(p.first, p.second+1));
                tomato[p.first][p.second+1] = 1;
                num_unripe--;
            }
            q.pop();
        }
        day++;
    }
    
    if(num_unripe != 0) { // not all ripen
        printf("%d\n", -1);
        return 0;
    }

    printf("%d\n", day-1);
    
    return 0;
}
