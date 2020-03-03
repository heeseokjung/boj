#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int N, T;
vector<int> v, cp, ans;

inline int absl(int x) {
    return x < 0 ? -x : x;
}

void find(int mx) {
    int s = 0, e = mx;
    while(s < e) {
        for(int i = 0; i < N; ++i)
            cp[i] = v[i];
        int m = (s + e)/2;
        int sum = 0;
        for(int i = 0; i < N-1; ++i) {
            if(cp[i+1] - cp[i] > m) {
                int diff = cp[i+1] - cp[i] - m;
                sum += diff;
                cp[i+1] -= diff;
            }
        }
        for(int i = N-1; i > 0; --i) {
            if(cp[i-1] - cp[i] > m) {
                int diff = cp[i-1] - cp[i] - m;
                sum += diff;
                cp[i-1] -= diff;
            }
        }
        if(sum > T) {
            s = m+1;
        } else {
            e = m;
            for(int i = 0; i < N; ++i)
                ans[i] = cp[i];
        }
    }
}

int main() {
    scanf("%d %d", &N, &T);
    v = vector<int>(N);
    cp = vector<int>(N);
    ans = vector<int>(N);
    for(int i = 0; i < N; ++i)
        scanf("%d", &v[i]);
    int mx = -1;
    for(int i = 0; i < N-1; ++i)
        mx = max(mx, absl(v[i] - v[i+1]));
    find(mx);
    for(int i = 0; i < N; ++i)
        printf("%d ", ans[i]);
    printf("\n");
    return 0;
}