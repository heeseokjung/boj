#include <cstdio>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

int N, M;
int neighbor[200001];
int count[200001];
bool visit[200001];
vector<int> adj[200001];
vector<int> time;
queue<pair<int, int> > q;

int main() {
    scanf("%d", &N);
    time = vector<int>(N+1, -1);
    for(int u = 1, v; u <= N; ++u) {
        while(true) {
            scanf("%d", &v);
            if(v == 0)
                break;
            adj[u].push_back(v);
            neighbor[u]++;
        }
    }

    scanf("%d", &M);
    for(int i = 0; i < M; ++i) {
        int x;
        scanf("%d", &x);
        visit[x] = true;
        time[x] = 0;
        q.push({x, 0});
    }

    while(!q.empty()) {
        int u = q.front().first;
        int t = q.front().second;
        q.pop();

        int size = (int)adj[u].size();
        for(int i = 0; i < size; ++i) {
            int v = adj[u][i];
            if(visit[v])
                continue;
            if(++count[v] >= (neighbor[v]/2 + neighbor[v]%2)) {
                visit[v] = true;
                time[v] = t + 1;
                q.push({v, time[v]});
            }
        }
    }

    for(int i = 1; i <= N; ++i)
        printf("%d ", time[i]);
    printf("\n");

    return 0;
}