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
    int s = 0, e = mx;
    while(s < e) {
        int m = (s + e)/2;
        int sum = 0;
        for(int i = 0; i < N-1; ++i) {
            if(absl(v[i] - v[i+1]) > m)
                sum += absl(v[i] - v[i+1]) - m;
        }
        if(sum > T)
            s = m+1;
        else
            e = m;
    }
    return s;
}

int main() {
    scanf("%d %d", &N, &T);
    v = vector<int>(N);
    for(int i = 0; i < N; ++i)
        scanf("%d", &v[i]);
    int mx = -1;
    for(int i = 0; i < N-1; ++i)
        mx = max(mx, absl(v[i] - v[i+1]));
    int x = find(mx);
    for(int i = 0; i < N-1; ++i) {
        if(absl(v[i] - v[i+1]) > x) {
            int diff = absl(v[i] - v[i+1]) - x;
            if(v[i] < v[i+1])
                v[i+1] -= diff;
            else
                v[i] -= diff;
        }
    }
    for(int i = 0; i < N; ++i)
        printf("%d ", v[i]);
    printf("\n");
    return 0;
}