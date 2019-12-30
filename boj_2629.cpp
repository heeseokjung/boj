#include <cstdio>
#include <vector>
using namespace std;

int N, M;
bool cache[31][15001];

void dp(int pos, int weight, vector<int>& v) {
    if(pos == N) {
        cache[pos][weight] = true;
        return;
    }
    if(cache[pos][weight]) {
        return;
    }
    cache[pos][weight] = true;
    dp(pos + 1, weight + v[pos], v);
    dp(pos + 1, weight, v);
    dp(pos + 1, (weight < v[pos]) ? v[pos] - weight : weight - v[pos], v);
}

int main() {
    scanf("%d", &N);
    vector<int> v(N);
    for(int i = 0; i < N; ++i)  
        scanf("%d", &v[i]);
    scanf("%d", &M);
    vector<int> query(M);
    for(int i = 0; i < M; ++i)
        scanf("%d", &query[i]);
    dp(0, 0, v);
    int size = (int)query.size();
    for(int i = 0, j = 0; i < size; ++i) {
        if(query[i] > 15000)
            printf("N ");
        else
            printf("%c ", cache[N][query[i]] ? 'Y' : 'N');
    }
    printf("\n");
    return 0;
}