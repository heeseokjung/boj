#include <cstdio>
#include <vector>
using namespace std;

struct Shark {
    int a, b, c;
};

int N;
vector<struct Shark> v;
vector<int> adj[100];
vector<int> visit, match;

int dfs(int l) {
    if(visit[l])
        return 0;
    visit[l] = 1;
    for(int i = 0; i < (int)adj[l].size(); ++i) {
        int r = adj[l][i];
        if(match[r] == -1 || dfs(match[r])) {
            match[r] = l;
            return 1;
        }
    }
    return 0;
}

int main() {
    scanf("%d", &N);
    v = vector<struct Shark>(N);
    for(int i = 0; i < N; ++i)
        scanf("%d %d %d", &v[i].a, &v[i].b, &v[i].c);

    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            if(i == j)
                continue;
            if(v[i].a == v[j].a && v[i].b == v[j].b && v[i].c == v[j].c) {
                if(i < j)
                    adj[i].push_back(j+N);
            } else if(v[i].a >= v[j].a && v[i].b >= v[j].b && v[i].c >= v[j].c) {
                adj[i].push_back(j+N);
            }
        }
    }

    int count = 0;
    match.assign(2*N, -1);
    for(int i = 0; i < N; ++i) {
        visit.assign(2*N, 0);
        count += dfs(i);
        visit.assign(2*N, 0);
        count += dfs(i);
    }

    printf("%d\n", N-count);
    
    return 0;
}