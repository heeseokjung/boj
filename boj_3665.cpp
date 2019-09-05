#include <stdio.h>
#include <utility>
#include <vector>
#include <queue>
using namespace std;

int tc, n, m;
vector<int> order;
vector<pair<int, int> > changed_order;
int indegree[501];
int adj[501][501];

void input()
{
    scanf("%d", &n);
    int x;
    order.reserve(n);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &x);
        order.push_back(x);
    }
    scanf("%d", &m);
    changed_order.reserve(m);
    int y;
    for(int i = 0; i < m; ++i) {
        scanf("%d %d", &x, &y);
        changed_order.push_back(pair<int, int>(x, y));
    }

    for(int i = 1; i <= n; ++i) {
        indegree[i] = 0;
        for(int j = 1; j <= n; ++j) {
            adj[i][j] = 0;
        }
    }
}

void run()
{
    scanf("%d", &tc);
    while(tc--) {
        input();

        for(int i = 0; i < n; ++i) {
            for(int j = i + 1; j < n; ++j) {
                adj[order[i]][order[j]] = 1;
                indegree[order[j]]++;
            }
        }
        for(int i = 0; i < m; ++i) {
            if(adj[changed_order[i].first][changed_order[i].second]) {
                adj[changed_order[i].first][changed_order[i].second] = 0;
                adj[changed_order[i].second][changed_order[i].first] = 1;
                indegree[changed_order[i].second]--;
                indegree[changed_order[i].first]++;
            }
            else if(adj[changed_order[i].second][changed_order[i].first]) {
                adj[changed_order[i].second][changed_order[i].first] = 0;
                adj[changed_order[i].first][changed_order[i].second] = 1;
                indegree[changed_order[i].first]--;
                indegree[changed_order[i].second]++;
            }
        }

        queue<int> q;
        for(int i = 1; i <= n; ++i) {
            if(!indegree[i])
                q.push(i);
        }
        vector<int> ans;
        ans.reserve(n);
        while(!q.empty()) {
            if(q.size() > 1)
                break;
            int u = q.front(); q.pop();
            ans.push_back(u);
            for(int i = 1; i <= n; ++i) {
                if(adj[u][i]) {
                    --adj[u][i];
                    if(--indegree[i] == 0)
                        q.push(i);
                }
            }
        }
        if(q.empty() && ans.size() != n) {
            printf("IMPOSSIBLE\n");
        }
        else if(!q.empty() && ans.size() != n) {
            printf("?\n");
        }
        else {
            for(int i = 0; i < n; ++i)
                printf("%d ", ans[i]);
            printf("\n");
        }

        order.clear();
        changed_order.clear();
    }
}

int main()
{
    run();
    return 0;
}