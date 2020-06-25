#include <cstdio>
#include <vector>
using namespace std;

int main() {
    int N;
    scanf("%d", &N);
    vector<int> v(N);
    for(int i = 0; i < N; ++i)
        scanf("%d", &v[i]);

    vector<int> dp(N, 0);
    dp[0] = v[0];
    for(int i = 1; i < N; ++i) {
        dp[i] = v[i];
        for(int j = 0; j < i; ++j) {
            if(v[j] < v[i] && dp[i] < dp[j] + v[i])
                dp[i] = dp[j] + v[i];
        }
    }

    int mx = 0;
    for(int i = 0; i < N; ++i)
        mx = (mx < dp[i] ? dp[i] : mx);
    printf("%d\n", mx);

    return 0;
}