// boj_14502

#include <stdio.h>
#include <utility>
#include <queue>
#include <vector>

using namespace std;

#define EMPTY 0 
#define WALL 1
#define VIRUS 2

int n, m;
int map[9][9];
int num_safe = 0, max_safe = 0;
vector<pair<int, int> > src;
vector<pair<int, int> > empty_to_wall;
vector<pair<int, int> > empty_space;
bool dfs_visit[64];

int virus();
void run(int cnt, int cur);

int main()
{
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            scanf("%d", &map[i][j]);
            if(map[i][j] == EMPTY) {
                num_safe++;
                empty_space.push_back(make_pair(i, j));
            }
            else if(map[i][j] == VIRUS)
                src.push_back(make_pair(i, j));
        }
    }
    for(int i = 0; i < empty_space.size(); ++i)
        dfs_visit[i] = false;

    run(0, 0);

    printf("%d\n", max_safe);

    return 0;
}

int virus()
{
    queue<pair<int, int> > q;
    for(int i = 0; i < src.size(); ++i)
        q.push(src[i]);

    int tmp_map[9][9];
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j)
            tmp_map[i][j] = map[i][j];
    }
    for(int i = 0; i < empty_to_wall.size(); ++i) {
        pair<int, int> p = empty_to_wall[i];
        tmp_map[p.first][p.second] = WALL;
    }

    int virus_spread = 0;
    while(!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();
        if(p.first > 1 && tmp_map[p.first-1][p.second] == EMPTY) {
            q.push(make_pair(p.first-1, p.second));
            tmp_map[p.first-1][p.second] = VIRUS;
        }
        if(p.first < n && tmp_map[p.first+1][p.second] == EMPTY) {
            q.push(make_pair(p.first+1, p.second));
            tmp_map[p.first+1][p.second] = VIRUS;
        }
        if(p.second > 1 && tmp_map[p.first][p.second-1] == EMPTY) {
            q.push(make_pair(p.first, p.second-1));
            tmp_map[p.first][p.second-1] = VIRUS;
        }
        if(p.second < m && tmp_map[p.first][p.second+1] == EMPTY) {
            q.push(make_pair(p.first, p.second+1));
            tmp_map[p.first][p.second+1] = VIRUS; 
        }
        virus_spread++;
    }

    return virus_spread;
}

void run(int cnt, int cur)
{
    if(cnt == 3) {
        int virus_spread = virus();
        if(max_safe < num_safe - virus_spread - 3 + src.size()) 
            max_safe = num_safe - virus_spread - 3 + src.size();
        return;
    }
    for(int i = cur; i < empty_space.size(); ++i) {
        if(!dfs_visit[i]) {
            dfs_visit[i] = true;
            pair<int, int> p = empty_space[i];
            empty_to_wall.push_back(make_pair(p.first, p.second));
            run(cnt + 1, i);
            empty_to_wall.pop_back();
            dfs_visit[i] = false;
        }
    }
}