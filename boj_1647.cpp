#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u;
    int v;
    int cost;
};

int N, M;
int disjoint[100001];
vector<Edge> edge_list;

int Find(int v) {
    int u = v;
    while(disjoint[u] > 0)
        u = disjoint[u];
    if(disjoint[v] > 0)
        disjoint[v] = u;
    return u;
}

void Union(int v1, int v2) {
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
}

inline bool compare(Edge& e1, Edge& e2) {
    return e1.cost < e2.cost;
}

int main() {
    scanf("%d %d", &N, &M);
    edge_list.reserve(M);
    int x, y, z;
    for(int i = 0; i < M; ++i) {
        scanf("%d %d %d", &x, &y, &z);
        edge_list.push_back(Edge{x, y, z});
    }
    sort(edge_list.begin(), edge_list.end(), compare);
    int sum = 0, mx = 0;
    for(int i = 0; i < M; ++i) {
        Edge e = edge_list[i];
        if(Find(e.u) != Find(e.v)) {
            Union(e.u, e.v);
            sum += e.cost;
            mx = (mx < e.cost) ? e.cost : mx;
        }
    }
    printf("%d\n", sum - mx);
    return 0;
}