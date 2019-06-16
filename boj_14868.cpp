#include <stdio.h>
#include <string.h>
#include <utility>
#include <vector>
#include <queue>

using namespace std;

int n, k, tmp, year = 0;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int arr[2001][2001] = {0, };
int disjoint[100001] = {0, };
typedef pair<int, int> ii;
vector<pair<ii, int> > org;

void input();
void run();
int Find(int v);
void Union(int v1, int v2);

int main()
{
    input();
    run();
    
    return 0;
}

void input()
{
    scanf("%d %d", &n, &k);
    int x, y;
    for(int i = 1; i <= k; ++i) {
        scanf("%d %d", &x, &y);
        pair<int, int> p = make_pair(x, y);
        org.push_back(make_pair(p, i));
        arr[x][y] = i;
    }
}

void run()
{
    queue<pair<ii, int> > s;
    queue<pair<ii, int> > q;
    tmp = k;
    for(int i = 0; i < k; ++i) {
        s.push(org[i]);
        q.push(org[i]);
    }

    while(!s.empty()) {
        pair<int, int> p = s.front().first;
        int civil_num = s.front().second;
        s.pop();
        int x, y;
        for(int i = 0; i < 4; ++i) {
            x = p.first + dx[i];
            y = p.second + dy[i];
            if(x < 1 || x > n || y < 1 || y > n)
                continue;
            if(arr[x][y] != 0 && Find(civil_num) != arr[x][y])
                Union(civil_num, arr[x][y]);
        }
    }

    if(k == 1) {
        printf("0\n");
        return;
    }

    memset(disjoint, 0, sizeof(disjoint));
    k = tmp;

    while(!q.empty()) {
        year++;
        int size = (int)q.size();
        for(int i = 0; i < size; ++i) {
            pair<int, int> p = q.front().first;
            int civil_num = q.front().second;
            q.pop();
            int x, y;
            for(int j = 0; j < 4; ++j) {
                x = p.first + dx[j];
                y = p.second + dy[j];
                if(x < 1 || x > n || y < 1 || y > n)
                    continue;
                if(arr[x][y] == 0) {
                    arr[x][y] = civil_num;
                    q.push(make_pair(make_pair(x, y), civil_num));

                    int xx, yy;
                    for(int k = 0; k < 4; ++k) {
                        xx = x + dx[k];
                        yy = y + dy[k];
                        if(xx < 1 || xx > n || yy < 1 || yy > n)
                            continue;
                        if(arr[xx][yy] != 0 && Find(civil_num) != Find(arr[xx][yy]))
                            Union(civil_num, arr[xx][yy]);
                    }
                }
                else if(arr[x][y] != 0 && Find(civil_num) != Find(arr[x][y])) {
                    Union(civil_num, arr[x][y]);
                }
            }
        }

        if(k == 1) {
            printf("%d\n", year);
            break;
        }
    }
}

int Find(int v)
{
    int u = v;
    while(disjoint[u] > 0)
        u = disjoint[u];
    if(disjoint[v] > 0)
        disjoint[v] = u;
    return u;
}

void Union(int v1, int v2)
{
    int r1 = Find(v1);
    int r2 = Find(v2);
    if(r1 == r2)
        return;
    if(disjoint[r1] < disjoint[r2])
        disjoint[r2] = r1;
    else if(disjoint[r1] > disjoint[r2])
        disjoint[r1] = r2;
    else {
        disjoint[r2] = r1;
        disjoint[r1]--;
    }
    k--;
}