#include <cstdio>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

int N, W;
int cache[1010][1010];
int p[1010][1010];
vector<pair<int, int> > v;

inline int absl(int x) {
    return x < 0 ? -x : x;
}

inline int dist(pair<int, int> p1, pair<int, int> p2) {
    return absl(p1.first - p2.first) + absl(p1.second - p2.second);
}

int dp(int i, int j) {
    int k = max(i, j) + 1;
    if(k == W+2)
        return 0;
    if(cache[i][j] != -1)
        return cache[i][j];
    int x = dp(k, j) + dist(v[i], v[k]);
    int y = dp(i, k) + dist(v[j], v[k]);
    if(x < y) {
        p[i][j] = 1;
        return cache[i][j] = x;
    } else {
        p[i][j] = 2;
        return cache[i][j] = y;
    }
}

int main() {
    scanf("%d %d", &N, &W);
    v.reserve(W+2);
    v.push_back(pair<int, int>(1, 1));
    v.push_back(pair<int, int>(N, N));
    for(int i = 0; i < W; ++i) {
        int r, c;
        scanf("%d %d", &r, &c);
        v.push_back(pair<int, int>(r, c));
    }
    for(int i = 0; i < W+2; ++i)
        for(int j = 0; j < W+2; ++j)
            cache[i][j] = -1;
    printf("%d\n", dp(0, 1));
    for(int i = 0, j = 1; max(i, j) + 1 < W+2; ) {
        printf("%d\n", p[i][j]);
        switch(p[i][j]) {
            case 1:
                i = max(i, j) + 1;
                break;
            case 2:
                j = max(i, j) + 1;
                break;
            default:
                break;
        }
    }
    return 0;
}