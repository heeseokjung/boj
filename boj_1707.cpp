// boj_1707

#include <cstdio>
#include <stdlib.h>
#include <vector>
#include <queue>

using namespace std;

#define UNVISIT 2
#define RED 1
#define BLUE 0

typedef struct TestCase
{
    int v, e;
    int* visit;
    vector<int>* adj;
}TestCase;

vector<TestCase> test;

bool BFS(int case_idx, int src)
{
    queue<int> q;
    q.push(src);
    bool is_bipartite = true;
    test[case_idx].visit[src] = RED;

    while(!q.empty() && is_bipartite) {
        int u = q.front(); q.pop();
        for(int i = 0; i < test[case_idx].adj[u].size(); ++i) {
            int v = test[case_idx].adj[u][i];
            if(test[case_idx].visit[v] == UNVISIT) {
                test[case_idx].visit[v] = 1 - test[case_idx].visit[u];
                q.push(v);
            }
            else if(test[case_idx].visit[v] == test[case_idx].visit[u]) {
                is_bipartite = false;
                break;
            }
        }
    }

    return is_bipartite;
}

void run(int num_test_case)
{
    for(int i = 0; i < num_test_case; ++i) {
        bool is_bipartite;
        for(int j = 1; j <= test[i].v; ++j) {
            if(test[i].visit[j] == UNVISIT) {
                is_bipartite = BFS(i, j);
                if(!is_bipartite)
                    break;
            }
        }
        is_bipartite ? printf("YES\n") : printf("NO\n");
    }
}

int main()
{
    // input
    int num_test_case;
    scanf("%d", &num_test_case);
    for(int i = 0; i < num_test_case; ++i) {
        int v, e;
        scanf("%d %d", &v, &e);
        TestCase tc;
        tc.v = v; tc.e = e;
        tc.adj = new vector<int>[v+1];
        tc.visit = new int[v+1];
        for(int j = 1; j <= v; ++j)
            tc.visit[j] = UNVISIT;
        int start, end;
        for(int j = 0; j < e; ++j) {
            scanf("%d %d", &start, &end);
            tc.adj[start].push_back(end);
            tc.adj[end].push_back(start);
        }
        test.push_back(tc);
    }

    run(num_test_case);

    return 0;
}