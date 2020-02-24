#include <cstdio>
#include <vector>
using namespace std;

int N;
int dp1[1000], dp2[1000];
int cnt[1000];
vector<int> v;

int main() {
    scanf("%d", &N);
    v.reserve(N);
    for(int i = 0; i < N; ++i)
        scanf("%d", &v[i]);
    dp1[0] = 1;
    for(int i = 0; i < N; ++i) {
        dp1[i] = 1;
        for(int j = 0; j < i; ++j) {
            if(v[j] < v[i])
                dp1[i] = max(dp1[i], dp1[j] + 1);
        }
    }
    dp2[N-1] = 1;
    for(int i = N-1; i >= 0; --i) {
        dp2[i] = 1;
        for(int j = N-1; j > i; --j) {
            if(v[i] > v[j])
                dp2[i] = max(dp2[i], dp2[j] + 1);
        }
    }
    int ans = 0;
    for(int i = 0; i < N; ++i) 
        ans = max(ans, dp1[i] + dp2[i] - 1);
    printf("%d\n", ans);
    return 0;
}