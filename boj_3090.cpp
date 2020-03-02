#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int N, T;
vector<int> v;

inline int absl(int x) {
    return x < 0 ? -x : x;
}

int find(int mx) {
    int i = 0, j = mx;
}

int main() {
    scanf("%d", &N);
    v = vector<int>(N);
    for(int i = 0; i < N; ++i)
        scanf("%d", &v[i]);
    int mx = -1;
    for(int i = 0; i < N-1; ++i)
        mx = max(mx, absl(v[i] - v[i+1]));
    printf("%d\n", find(mx));
    return 0;
}