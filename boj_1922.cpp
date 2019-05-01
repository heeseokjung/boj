#include <cstdio>
#include <utility>
#include <map>

using namespace std;

int N, M;
int disjoint[1001] = {0, };
typedef pair<int, int> Edge;
multimap<int, Edge> edge_list;

int Find(int v);
void Union(int v1, int v2);

void run()
{
    int cost = 0;
    multimap<int, Edge>::iterator it;
    for(it = edge_list.begin(); it != edge_list.end(); ++it) {
        int weight = it->first;
        Edge e = it->second;
        if(Find(e.first) != Find(e.second)) {
            Union(Find(e.first), Find(e.second));
            cost += weight;
        }
        else
            continue;
    }

    printf("%d\n", cost);
}

int main()
{
    scanf("%d %d", &N, &M);
    for(int i = 0; i < M; ++i) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        Edge e = make_pair(u, v);
        edge_list.insert(make_pair(w, e));
    }
    
    run();

    return 0;
}

int Find(int v)
{
    while(disjoint[v] > 0)
        v = disjoint[v];
    return v;
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
}