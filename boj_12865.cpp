#include <cstdio>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

int N, K;
int dp[100][100001];
vector<pair<int, int> > v;

int main() {
    scanf("%d %d", &N, &K);
    v.reserve(N);
    int weight, val;
    for(int i = 0; i < N; ++i) {
        scanf("%d %d", &weight, &val);
        v.push_back(pair<int, int>(weight, val));
    }
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j <= K; ++j) {
            dp[i][j] = (i == 0) ? 0 : dp[i-1][j];
            if(j - v[i].first >= 0)
                dp[i][j] = max(dp[i][j], (i == 0 ? 0 : dp[i-1][j-v[i].first]) + v[i].second);
        }
    }
    printf("%d\n", dp[N-1][K]);
    return 0;
}