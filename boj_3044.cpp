#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> adj[10001];
vector<int> radj[10001];
bool visit [10001];
bool rvisit [10001];
bool finish [10001];
bool valid [10001];
bool ovf [10001];
bool inf = false;
int dist[10001];
#define MOD 1000000000

void dfs(int u) {
    visit[u] = true;
    int size = (int)adj[u].size();
    for(int i = 0; i < size; ++i) {
        int v = adj[u][i];
        if(!visit[v])
            dfs(v);
    }
}

void rdfs(int u) {
    rvisit[u] = true;
    int size = (int)radj[u].size();
    for(int i = 0; i < size; ++i) {
        int v = radj[u][i];
        if(!rvisit[v])
            rdfs(v);
    }
}

void topological_sort(int u, vector<int>& s) {
    visit[u] = true;
    int size = (int)adj[u].size();
    for(int i = 0; i < size; ++i) {
        int v = adj[u][i];
        if(valid[v]) {
            if(!visit[v])
                topological_sort(v, s);
            else if(!finish[v])
                inf = true;
        }
    }
    s.push_back(u);
    finish[u] = true;
}

int main() {
    scanf("%d %d", &N, &M);
    for(int i = 0; i < M; ++i) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        radj[v].push_back(u);
    }

    dfs(1);
    rdfs(2);
    for(int i = 1; i <= N; ++i) {
        if(visit[i] && rvisit[i])
            valid[i] = true;
    }

    for(int i = 1; i <= N; ++i) 
        visit[i] = false;
    vector<int> s;
    topological_sort(1, s);
    reverse(s.begin(), s.end());

    if(inf) {
        printf("inf\n");
    } else {
        int pos = 0;
        while(s[pos] != 1)
            pos++;
        dist[1] = 1;
        for(int i = pos; i < (int)s.size(); ++i) {
            int u = s[i];
            if(u == 2)
                break;
            for(int j = 0; j < (int)adj[u].size(); ++j) {
                int v = adj[u][j];
                if(ovf[u])
                    ovf[v] = true;
                dist[v] += dist[u];
                if(dist[v] >= MOD) {
                    dist[v] %= MOD;
                    ovf[v] = true;
                }
            }
        }
        printf((ovf[2] ? "%09d\n" : "%d\n"), dist[2]);
    }
    return 0;
}