#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int N, M;
int indegree[32001];
vector<int> adj[32001];

int main() {
    scanf("%d %d", &N, &M);
    for(int i = 0; i < M; ++i) {
        int x, y;
        scanf("%d %d", &x, &y);
        adj[x].push_back(y);
        indegree[y]++;
    }
    priority_queue<int, vector<int>, greater<int> > pq;
    for(int i = 1; i <= N; ++i) {
        if(indegree[i] == 0)
            pq.push(i);
    }
    while(!pq.empty()) {
        int x = pq.top(); pq.pop();
        int size = (int)adj[x].size();
        for(int i = 0; i < size; ++i) {
            if(--indegree[adj[x][i]] == 0)
                pq.push(adj[x][i]);
        }
        printf("%d ", x);
    }
    printf("\n");
    return 0;
}