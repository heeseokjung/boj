#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

int num_com, num_edge;
vector<int> adj[101];
bool visit[101] = {false, };

void input()
{
    scanf("%d %d", &num_com, &num_edge);
    for(int i = 0; i < num_edge; ++i) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

int bfs(int x)
{
    queue<int> q;
    visit[x] = true;
    q.push(x);
    int num_infected = 0;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(int i = 0; i < (int)adj[u].size(); ++i) {
            if(!visit[adj[u][i]]) {
                visit[adj[u][i]] = true;
                q.push(adj[u][i]);
                num_infected++;
            }
        }
    } 

    return num_infected;   
}

void run()
{
    printf("%d\n", bfs(1));
}

int main()
{
    input();
    run();

    return 0;
}