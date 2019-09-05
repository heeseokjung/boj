#include <cstdio>
#include <string.h>
#include <vector>
#include <queue>

#define INF 1000000000

using namespace std;

int n, k, w;
int time[1001];
int indegree[1001] = {0, };
int answer[1001];
vector<int> print;

void run(vector<int>* adj);

int main()
{
    int num_case;
    scanf("%d", &num_case);

    for(int i = 0; i < num_case; ++i) {
        scanf("%d %d", &n, &k);
        
        for(int i = 1; i <= n; ++i)
            scanf("%d", &time[i]);

        int u, v;
        vector<int> adj[1001];
        memset(indegree, 0, sizeof(int) * (n + 1));
        for(int i = 0; i < k; ++i) {
            scanf("%d %d", &u, &v);
            adj[u].push_back(v);
            indegree[v]++;
        }

        scanf("%d", &w);

        run(adj);
    }

    for(int i = 0; i < (int)print.size(); ++i)
        printf("%d\n", print[i]);

    return 0;
}

void run(vector<int>* adj)
{
    memset(answer, 0, sizeof(int) * (n + 1));
    
    queue<int> q;
    for(int i = 1; i <= n; ++i) {
        if(indegree[i] == 0) {
            answer[i] = time[i];
            q.push(i);
        }
    }

    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(int i = 0; i < (int)adj[u].size(); ++i) {
            int v = adj[u][i];
            if(answer[v] < answer[u] + time[v])
                answer[v] = answer[u] + time[v];
            if(--indegree[v] == 0)
                q.push(v);
        }
    }

    print.push_back(answer[w]);
}