// boj_11657

#include <cstdio>
#include <utility>
#include <vector>

using namespace std;

#define INF 1000000000

int N, M;
int dist[501];
typedef pair<int, int> ii;
vector<pair<int, ii> > edge_list;

void run(int src)
{   
    dist[src] = 0;
    bool is_negative_cycle = false;
    for(int i = 1; i <= N; ++i) {
        bool is_relaxed = false;
        for(int j = 0; j < (int)edge_list.size(); ++j) {
            int u = edge_list[j].first;
            int v = edge_list[j].second.first;
            int w = edge_list[j].second.second;
            if(dist[u] + w < dist[v] && dist[u] != INF) {
                is_relaxed = true;
                if(i == N)
                    is_negative_cycle = true;
                dist[v] = dist[u] + w;
            }
        }
        if(!is_relaxed)
            break;
    }

    if(is_negative_cycle)
        printf("%d\n", -1);
    else {
        for(int i = 2; i <= N; ++i) {
            if(dist[i] == INF)
                printf("%d\n", -1);
            else
                printf("%d\n", dist[i]);
        }
    }
}

int main()
{
    scanf("%d %d", &N, &M);
    for(int i = 0; i < M; ++i) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        edge_list.push_back(make_pair(u, make_pair(v, w)));
    }
    for(int i = 1; i <= N; ++i)
        dist[i] = INF;

    run(1);

    return 0;
}