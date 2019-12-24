#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<pair<int, int> > v;
int dp[500];

int main() {
    scanf("%d", &N);
    v.reserve(N);
    int x, y;
    for(int i = 0; i < N; ++i) {
        scanf("%d %d", &x, &y);
        v.push_back(pair<int, int>(x, y));
    }
    sort(v.begin(), v.end());
    int size = (int)v.size(), mx = -1;
    for(int i = 0; i < size; ++i)
        dp[i] = 1;
    for(int i = 0; i < size; ++i) {
        for(int k = 0; k < i; ++k) {
            if(v[k].second < v[i].second)
                dp[i] = max(dp[i], dp[k] + 1);
        }
        mx = max(mx, dp[i]);
    }
    printf("%d\n", size - mx);
    return 0;
}