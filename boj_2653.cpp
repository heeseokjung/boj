#include <cstdio>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int dfs_count = 0, scc_count = 0;
int adj[100][100];
bool visit[100];
int dfs_low[100];
int dfs_num[100];
int scc_num[100];
vector<int> scc[100];

void tarjan(stack<int>& s, int x) {
    visit[x] = true;
    dfs_num[x] = dfs_low[x] = ++dfs_count;
    s.push(x);
    for(int i = 0; i < N; ++i) {
        if(i == x)
            continue;
        if(adj[x][i] == 0 && !visit[i])
            tarjan(s, i);
        if(adj[x][i] == 0 && visit[i] && dfs_low[i] < dfs_low[x])
            dfs_low[x] = dfs_low[i];
    }
    if(dfs_num[x] == dfs_low[x]) {
        while(true) {
            int top = s.top(); s.pop();
            scc_num[top] = scc_count;
            scc[scc_num[top]].push_back(top);
            if(top == x)
                break;
        }
        scc_count++;
    }
}

inline bool comp(vector<int>& v1, vector<int>& v2) {
    return v1[0] < v2[0];
}

int main() {
    scanf("%d", &N);
    for(int i = 0; i < N; ++i)
        for(int j = 0; j < N; ++j)
            scanf("%d", &adj[i][j]);
    stack<int> s;
    for(int i = 0; i < N; ++i) {
        if(!visit[i])
            tarjan(s, i);
    }
    bool is_stable = true;
    for(int i = 0; i < scc_count; ++i) {
        int size = (int)scc[i].size();
        if(size == 1) {
            is_stable = false;
            break;
        }
        for(int j = 0; j < size; ++j) {
            int x = scc[i][j];
            for(int k = 0; k < N; ++k) {
                if(k == x) {  
                    continue;
                }
                if(scc_num[k] != scc_num[x] && adj[x][k] == 0) {
                    is_stable = false;
                    break;
                }
            }
        }
    }
    if(is_stable) {
        for(int i = 0; i < scc_count; ++i)
            sort(scc[i].begin(), scc[i].end());
        sort(scc, scc + scc_count);
        printf("%d\n", scc_count);
        for(int i = 0; i < scc_count; ++i) {
            int size = (int)scc[i].size();
            for(int j = 0; j < size; ++j)
                printf("%d ", scc[i][j]+1);
            printf("\n");
        }
        
    } else {
        printf("0\n");
    }
    return 0;
}