#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int N, K;
int dp[10001];
vector<int> v;
#define INF 1e9

int main() {
    scanf("%d %d", &N, &K);
    for(int i = 0; i <= K; ++i)
        dp[i] = INF;
    int x;
    v.reserve(N);
    for(int i = 0; i < N; ++i) {
        scanf("%d", &x);
        if(x <= K)
            dp[x] = 1;
        v.push_back(x);
    }
    int size = (int)v.size();
    for(int i = 1; i <= K; ++i) {
        for(int j = 0; j < size; ++j) {
            if(i - v[j] > 0 && dp[i-v[j]] + 1 < dp[i])
                dp[i] = dp[i-v[j]] + 1;
        }
    }
    printf("%d\n", (dp[K] == INF) ? -1 : dp[K]);
    return 0;
}