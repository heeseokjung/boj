#include <cstdio>
#include <utility>
#include <vector>
using namespace std;

int N, max_level = 1;
int indegree[10001];
int col[10001];
pair<int, int> adj[10001];
pair<int, int> num_child[10001];
vector<int> level[10001];

int get_num_child(int x) {
    int l = adj[x].first;
    int r = adj[x].second;
    if(l == -1 && r == -1)
        return 1;
    if(l != -1) {
        l = get_num_child(l);
    }
    if(r != -1) {
        r = get_num_child(r);
    }
    l = (l == -1) ? 0 : l;
    r = (r == -1) ? 0 : r;
    num_child[x] = pair<int, int>(l, r);
    return l + r + 1;
}

void partition(int i, int j, int x, int lv) {
    int lchild = num_child[x].first;
    int rchild = num_child[x].second;
    col[x] = i + lchild;
    level[lv].push_back(col[x]);
    max_level = (max_level < lv) ? lv : max_level;
    if(lchild > 0)
        partition(i, i + lchild - 1, adj[x].first, lv + 1);
    if(rchild > 0)
        partition(i + lchild + 1, j, adj[x].second, lv + 1);
}

int main() {
    scanf("%d", &N);
    int x, y, z;
    for(int i = 0; i < N; ++i) {
        scanf("%d %d %d", &x, &y, &z);
        adj[x] = pair<int, int>(y, z);
        indegree[y]++; indegree[z]++;
    }

    int root = 1;
    while(indegree[root])
        root++;
    get_num_child(root);
    partition(1, N, root, 1);

    int max_width = 1, w, l = 1;
    for(int i = 1; i <= max_level; ++i) {
        if(level[i].size() > 1)
            w = level[i][level[i].size()-1] - level[i][0] + 1;
        else
            w = 1;
        if(w > max_width) {
            max_width = w;
            l = i;
        }
    }
    printf("%d %d\n", l, max_width);
    return 0;
}