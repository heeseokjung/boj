#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

int N, M;
vector<int> adj[1001];
bool visit[1001];
bool back[1001];

void dfs(int x, vector<int>& s) {
    visit[x] = back[x] = true;
    int size = (int)adj[x].size();
    for(int i = 0; i < size; ++i) {
        int v = adj[x][i];
        if(!visit[v]) {
            dfs(v, s);
        }
        else if(back[v]) {
            printf("0\n");
            exit(0);
        }
    }
    back[x] = false;
    s.push_back(x);
}

int main() {
    scanf("%d %d", &N, &M);
    vector<int> v;
    for(int i = 0; i < M; ++i) {
        int num;
        scanf("%d", &num);
        v.reserve(num);
        int x;
        for(int j = 0; j < num; ++j) {
            scanf("%d", &x);
            for(int k = 0; k < j; ++k)
                adj[v[k]].push_back(x);
            v.push_back(x);
        }
        v.clear();
    }
    vector<int> s;
    for(int i = 1; i <= N; ++i) {
        if(!visit[i])
            dfs(i, s);
    }
    int size = (int)s.size();
    for(int i = size-1; i >= 0; --i)
        printf("%d\n", s[i]);
    return 0;
}