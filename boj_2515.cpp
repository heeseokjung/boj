#include <cstdio>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

int N, S;
vector<pair<int, int> > v;
int dp[300000];

int main() {
    scanf("%d %d", &N, &S);
    v = vector<pair<int, int> >(N);
    for(int i = 0; i < N; ++i) {
        scanf("%d %d", &v[i].first, &v[i].second);
    }
    sort(v.begin(), v.end());
    dp[0] = v[0].second;
    int pos = 0, mx = 0, ans = dp[0];
    for(int i = 1; i < N; ++i) {
        while(pos < i && v[i].first - v[pos].first >= S) {
            mx = (mx < dp[pos]) ? dp[pos] : mx;
            pos++;
        }
        dp[i] = mx + v[i].second;
        ans = (ans < dp[i]) ? dp[i] : ans;
    }
    printf("%d\n", ans);
    return 0;
}