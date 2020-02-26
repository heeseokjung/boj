#include <cstdio>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

int N, W;
int dp[1000][2];
int c[1000];
vector<pair<int, int> > v;

inline int absl(int x) {
    return x < 0 ? -x : x;
}

inline int dist(pair<int, int> p1, pair<int, int> p2) {
    return absl(p1.first - p2.first) + absl(p1.second - p2.second);
}

int main() {
    scanf("%d %d", &N, &W);
    v.reserve(W);
    for(int i = 0; i < W; ++i) {
        int r, c;
        scanf("%d %d", &r, &c);
        v.push_back(pair<int, int>(r, c));
    }
    pair<int, int> p[2];
    p[0] = pair<int, int>(1, 1);
    p[1] = pair<int, int>(N, N);
    dp[0][0] = dist(p[0], v[0]);
    dp[0][1] = dist(p[1], v[0]);
    if(dp[0][0] < dp[0][1]) {
        c[0] = 0;
        p[0] = v[0];
    } else {
        c[0] = 1;
        p[1] = v[0];
    }
    for(int i = 1; i < W; ++i) {
        for(int j = 0; j < 2; ++j) {
            dp[i][j] = dp[i-1][j] + dist(v[i-1], v[i]);
            dp[i][j] = min(dp[i][j], dp[i-1][1-j] + dist(p[j], v[i]));
        }
        if(dp[i][0] < dp[i][1]) {
            c[i] = 0;
            p[0] = v[i];
        } else {
            c[i] = 1;
            p[1] = v[i];
        }
    }
    printf("%d\n", dp[W-1][c[W-1]]);
    for(int i = 0; i < W; ++i)
        printf("%d\n", c[i]+1);
    return 0;
}