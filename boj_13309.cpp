#include <stdio.h>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

#define INF -1
int n, q;
vector<int> adj[200001];
int dfs_count = 1;
int dfs_tree[200001];
int dfs_num[200001];
int dfs_depth[200001];
int desc_num[200001];
int parent[200001][20];

typedef struct Query
{
    int b;
    int c;
    int d;
}Query;
vector<Query> query;

class SegmentTree
{
private:
    vector<int> tree;
    vector<int> lazy;
public:
    SegmentTree(int i, int j);
    int init_tree_max(int i, int x, int j);
    void update_lazy(int x, int i, int j);
    int max_query(int x, int i, int j, int l, int r);
    void update_max(int x, int i, int j, int l, int r, int val);
};

SegmentTree::SegmentTree(int i, int j)
{
    int h = (int)ceil(log2(n));
    int tree_size = (1 << (h+1));
    tree = vector<int>(tree_size);
    lazy = vector<int>(tree_size);

    init_tree_max(i, 1, j);
}

int SegmentTree::init_tree_max(int i, int x, int j)
{
    if(i == j)
        return tree[x] = 1;
    int lmax = init_tree_max(i, x*2, (i + j)/2);
    int rmax = init_tree_max((i + j)/2 + 1, x*2 + 1, j);
    return tree[x] = (lmax < rmax) ? rmax : lmax;
}

void SegmentTree::update_lazy(int x, int i, int j)
{
    if(lazy[x] != 0) {
        tree[x] = max(tree[x], lazy[x]);
        if(i != j) {
            lazy[x*2] = max(lazy[x*2], lazy[x]);
            lazy[x*2+1] = max(lazy[x*2+1], lazy[x]);
        }
        lazy[x] = 0;
    }
}

int SegmentTree::max_query(int x, int i, int j, int l, int r)
{
    update_lazy(x, i, j);
    if(l > j || r < i)
        return INF;
    if(l <= i && j <= r)
        return tree[x];
    int lmax = max_query(x*2, i, (i + j)/2, l, r);
    int rmax = max_query(x*2 + 1, (i + j)/2 + 1, j, l, r);
    return (lmax < rmax) ? rmax : lmax;
}

void SegmentTree::update_max(int x, int i, int j, int l, int r, int val)
{
    update_lazy(x, i, j);
    if(l > j || r < i)
        return;
    if(l <= i && j <= r) {
        tree[x] = max(tree[x], val);
        if(i != j) {
            lazy[x*2] = max(lazy[x*2], val);
            lazy[x*2+1] = max(lazy[x*2+1], val);
        }
        return;
    }
    update_max(x*2, i, (i + j)/2, l, r, val);
    update_max(x*2 + 1, (i + j)/2 + 1, j, l, r, val);
    tree[x] = max(tree[x*2], tree[x*2+1]);
}

void input()
{
    scanf("%d %d", &n, &q);
    int p;
    for(int i = 1; i <= n - 1; ++i) {
        scanf("%d", &p);
        parent[i+1][0] = p;
        adj[p].push_back(i+1);
    }
    int b, c, d;
    for(int i = 0; i < q; ++i) {
        scanf("%d %d %d", &b, &c, &d);
        query.push_back(Query{b, c, d});
    }
}

void dfs(int x, int depth)
{
    dfs_num[x] = dfs_count++;
    dfs_tree[dfs_num[x]] = x;
    dfs_depth[dfs_num[x]] = depth;
    
    for(int i = 0; i < (int)adj[x].size(); ++i)
        dfs(adj[x][i], depth + 1);
    
    desc_num[dfs_num[x]] = dfs_count - 1;
}

int find_root(SegmentTree& st, int x)
{
    x = dfs_num[x];
    int max_depth = st.max_query(1, 1, n, x, x);
    for(int i = 20; i >= 0; --i) {
        if(dfs_depth[x] - max_depth >= (1 << i))
            x = dfs_num[parent[dfs_tree[x]][i]];
    }
    return dfs_tree[x];
}

void run()
{
    dfs(1, 1);
    SegmentTree st = SegmentTree(1, n);
    for(int j = 1; j < 20; ++j) {
        for(int i = 1; i <= n; ++i)
            parent[i][j] = parent[parent[i][j-1]][j-1];
    }

    int b, c, d;
    for(int i = 0; i < (int)query.size(); ++i) {
        b = query[i].b, c = query[i].c, d = query[i].d;
        if(d) {
            if(find_root(st, b) == find_root(st, c)) {
                printf("YES\n");
                st.update_max(1, 1, n, dfs_num[b], desc_num[dfs_num[b]], dfs_depth[dfs_num[b]]);
            }
            else {
                printf("NO\n");
                st.update_max(1, 1, n, dfs_num[c], desc_num[dfs_num[c]], dfs_depth[dfs_num[c]]);
            }
        }
        else {
            if(find_root(st, b) == find_root(st, c))
                printf("YES\n");
            else 
                printf("NO\n");
        }
    }
}

int main()
{
    input();
    run();
    
    return 0;
}