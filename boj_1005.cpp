#include <stdio.h>
#include <string.h>
#include <utility>
#include <vector>

using namespace std;

typedef struct Building
{
    int bid;
    int time;
}Building;

typedef pair<int, int> Edge;

int n, k, w;
Building building[1001];
int indegree[1001] = {0, };
vector<Edge> edge_list;
vector<int> ans;

void run();

int main()
{
    int num_case;
    scanf("%d", &num_case);

    for(int i = 0; i < num_case; ++i) {
        scanf("%d %d", &n, &k);
        edge_list.reserve(k);
        
        int time;
        for(int i = 1; i <= n; ++i) {
            scanf("%d", &time);
            building[i].time = time;
        }

        int u, v;
        memset(indegree + 1, 0, n);
        for(int i = 0; i < k; ++i) {
            scanf("%d %d", &u, &v);
            indegree[u]++;
            edge_list.push_back(make_pair(v, u));
        }

        scanf("%d", &w);

        run();
    }
    
    return 0;
}