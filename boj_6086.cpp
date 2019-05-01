#include <cstdio>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX_NODE 52

int N, max_flow = 0;
bool visit[MAX_NODE + 1] = {false, };
int adj[MAX_NODE + 1][MAX_NODE + 1] = {0, };
vector<pair<int, int> > s;

inline int get_idx(char c)
{
    int i = (int)c;
    if(c >= 65 && c <= 90)
        return i - 64;
    else if(c >= 97 && c <= 122)
        return i - 70;
}

void run();
void dfs(int src, int sink);

int main()
{
    scanf("%d", &N);
    char src, dest;
    int capacity;
    for(int i = 0; i < N; ++i) {
        scanf(" %c %c %d", &src, &dest, &capacity);
        adj[get_idx(src)][get_idx(dest)] += capacity;
        adj[get_idx(dest)][get_idx(src)] += capacity;
    }

    run();

    return 0;
}

int calculate_flow()
{
    // find min capacity
    int min_capacity = 1000;
    for(int i = 0; i < (int)s.size(); ++i) {
        pair<int, int> p = s[i];
        if(adj[p.first][p.second] < min_capacity)
            min_capacity = adj[p.first][p.second];
    }

    for(int i = 0; i < (int)s.size(); ++i) {
        pair<int, int> p = s[i];
        adj[p.first][p.second] -= min_capacity;
        adj[p.second][p.first] += min_capacity;
    }

    return min_capacity;
}

void dfs(int src, int sink)
{
    visit[src] = true;
    if(src == sink) {
        int min_capacity = calculate_flow();
        max_flow += min_capacity;
        return;
    }
    for(int i = 1; i <= MAX_NODE; ++i) {
        if(adj[src][i] != 0 && !visit[i]) {
            s.push_back(make_pair(src, i));
            dfs(i, sink);
            s.pop_back();
            visit[i] = false;
        }
    }
    visit[src] = false;
}

void run()
{
    dfs(get_idx('A'), get_idx('Z'));

    printf("%d\n", max_flow);
}