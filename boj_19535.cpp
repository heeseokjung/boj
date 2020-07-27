#include <cstdio>
#include <utility>
#include <vector>
using namespace std;

int N;
int indegree[300001];
typedef unsigned long long ull_t;
unsigned long long D, G;
vector<pair<int, int> > edge;

int main() {
    scanf("%d", &N);
    edge.reserve(N-1);
    int u, v;
    for(int i = 0; i < N-1; ++i) {
        scanf("%d %d", &u, &v);
        edge.push_back({u, v});
        indegree[u]++;
        indegree[v]++;
    }

    for(int i = 0; i < N-1; ++i) {
        D += (ull_t)(indegree[edge[i].first]-1) * (ull_t)(indegree[edge[i].second]-1);
    }
    
    for(int i = 1; i <= N; ++i) {
        if(indegree[i] >= 3) {
            ull_t n = (ull_t)indegree[i];
            G += n*(n-1)*(n-2)/6;
        }
    }

    if(D == 3*G)
        printf("DUDUDUNGA\n");
    else if(D > 3*G)
        printf("D\n");
    else if(D < 3*G)
        printf("G\n");

    return 0;
}