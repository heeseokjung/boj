#include <cstdio>
#include <utility>
#include <vector>
#include <queue>

using namespace std;

#define SRC 0
#define SINK N + M + 1

int N, M;
int max_flow = 0;
bool visit[2002] = {false, };
int parent[2002];
vector<pair<int, int> > adj[2002];
vector<int> path;

void run();
void get_path(int x);

int main()
{
    scanf("%d %d", &N, &M);
    int work_capacity, num_work;
    for(int i = 1; i <= N; ++i) {
        scanf("%d", &work_capacity);
        for(int j = 0; j < work_capacity; ++j) {
            scanf("%d", &num_work);
            adj[i].push_back(make_pair(num_work + N, 1));
        }
    }
    for(int i = 1; i <= N; ++i) // Link source
        adj[SRC].push_back(make_pair(i, 1));
    for(int i = N + 1; i <= N + M; ++i) // Link sink
        adj[i].push_back(make_pair(SINK, 1));

    run();

    return 0;
}

void run()
{
    while(true) {
        for(int i = SRC; i <= SINK; ++i) {
            parent[i] = i;
            visit[i] = false;
        }
        queue<int> q;
        visit[SRC] = true;
        q.push(SRC);
        while(!q.empty()) {
            int u = q.front(); q.pop();
            for(int i = 0; i < (int)adj[u].size(); ++i) {
                int v = adj[u][i].first;
                if(!visit[v]) {
                    visit[v] = true;
                    parent[v] = u;
                    q.push(v);
                }
            }
        }

        if(parent[SINK] == SINK) // No augmenting path
            break;
        path.clear();
        get_path(SINK);

        for(int i = 0; i < (int)path.size() - 1; ++i) {
            int u = path[i];
            int v = path[i+1];
            vector<pair<int, int> >::iterator it;
            for(it = adj[u].begin(); it != adj[u].end(); ++it) {
                if(it->first == v) {
                    if(--it->second == 0)
                        it = adj[u].erase(it);
                    break;
                }
            }
            bool found = false;
            for(it = adj[v].begin(); it != adj[v].end(); ++it) {
                if(it->first == u) {
                    found = true;
                    it->second++;
                    break;
                }
            }
            if(!found)
                adj[v].push_back(make_pair(u, 1));
        }

        max_flow++;
    }

    printf("%d\n", max_flow);
}

void get_path(int x)
{
    if(x == SRC) {
        path.push_back(x);
        return;
    }
    get_path(parent[x]);
    path.push_back(x);
}