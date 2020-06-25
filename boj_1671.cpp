#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct Shark {
    int a;
    int b;
    int c;
};

int N;
int adj[50][50];
bool visit[50];
int sum[50];
vector<struct Shark> v;

int dfs(int x) {
    visit[x] = true;
    vector<int> v;
    for(int i = 0; i < N; ++i) {
        if(adj[x][i] && !visit[i])
            v.push_back(dfs(i));
    }
    
}

int main() {
    scanf("%d", &N);
    v = vector<struct Shark>(N);
    for(int i = 0; i < N; ++i)
        scanf("%d %d %d", &v[i].a, &v[i].b, &v[i].c);

    for(int i = 0; i < N; ++i)
        for(int j = 0; j < N; ++j)
            adj[i][j] = 0;
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            if(v[i].a >= v[j].a && v[i].b >= v[i].b && v[i].c >= v[j].c)
                adj[i][j] = 1;
        }
    }

    for(int i = 0; i < N; ++i)
        visit[i] = false;
    for(int i = 0; i < N; ++i) {
        if(!visit[i])
            dfs(i);
    }

    return 0;
}