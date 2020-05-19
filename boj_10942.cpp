#include <cstdio>
#include <utility>
#include <vector>
using namespace std;

int N, M;
vector<int> v;
vector<pair<int, int> > query;
int cache[2000][2000];

int dp(int s, int e) {
    if(s == e)
        return cache[s][e] = 1;
    if(e == s + 1)
        return cache[s][e] = (v[s] == v[e] ? 1 : 0);
    if(cache[s][e] != -1)
        return cache[s][e];
    return cache[s][e] = (dp(s + 1, e - 1) == 1 && v[s] == v[e] ? 1 : 0);
}

int main() {
    scanf("%d", &N);
    v = vector<int>(N);
    for(int i = 0; i < N; ++i)
        scanf("%d", &v[i]);
    scanf("%d", &M);
    query = vector<pair<int, int> >(M);
    for(int i = 0; i < M; ++i) {
        scanf("%d %d", &query[i].first, &query[i].second);
        --query[i].first; --query[i].second;
    }

    for(int i = 0; i < N; ++i)
        for(int j = 0; j < N; ++j)
            cache[i][j] = -1;

    for(int i = 0; i < M; ++i)
        printf("%d\n", dp(query[i].first, query[i].second));

    return 0;
}