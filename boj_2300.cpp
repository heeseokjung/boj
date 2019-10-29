#include <cstdio>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int dp[10000];
vector<pair<int, int> > v;

inline int abs(int x) {
    return x < 0 ? -x : x;
}

int main() {
    scanf("%d", &N);
    int x, y;
    v.reserve(N);
    for(int i = 0; i < N; ++i) {
        scanf("%d %d", &x, &y);
        v.push_back(pair<int, int>(x, y));
    }

    sort(v.begin(), v.end());
    dp[0] = abs(v[0].second)*2;
    for(int i = 1; i < N; ++i) {
        int height = abs(v[i].second);
        dp[i] = dp[i-1] + height*2;
        for(int j = i-1; j >= 0; --j) {
            height = max(height, abs(v[j].second));
            dp[i] = min(dp[i], max(height*2, v[i].first - v[j].first) + (j > 0 ? dp[j-1] : 0));
        }
    }
    printf("%d\n", dp[N-1]);
    return 0;
}