#include <cstdio>
#include <utility>
#include <algorithm>
using namespace std;

int N, M;
pair<int, int> app[100];
long long dp[10001];

int main() {
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; ++i)
        scanf("%d", &app[i].first);
    int max_cost = 0;
    for(int i = 0; i < N; ++i) {
        scanf("%d", &app[i].second);
        max_cost += app[i].second;
    }
    for(int i = 0; i < N; ++i) {
        for(int j = max_cost; j >= app[i].second; --j) {
            dp[j] = max(dp[j], dp[j - app[i].second] + app[i].first);
        }
    }
    for(int i = 0; i <= max_cost; ++i) {
        if(dp[i] >= M) {
            printf("%d\n", i);
            break;
        }
    }
    return 0;
}