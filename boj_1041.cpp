#include <cstdio>
#include <vector>
using namespace std;

inline void swap(long long& l, long long& r) {
    long long tmp = l;
    l = r;
    r = tmp;
}

int main() {
    long long N;
    scanf("%lld", &N);
    vector<int> v(6);
    for(int i = 0; i < 6; ++i)
        scanf("%d", &v[i]);

    int adj[6][4] = {{1, 2, 4, 3},
                     {0, 2, 5, 3},
                     {0, 1, 5, 4},
                     {0, 1, 5, 4},
                     {0, 2, 5, 3},
                     {1, 2, 4, 3}};
    if(N == 1) {
        int sum = 0, mx = 0;
        for(int i = 0; i < 6; ++i) {
            sum += v[i];
            if(mx < v[i])
                mx = v[i];
        }
        printf("%d\n", sum - mx);
    } else {
        long long mn = -1;
        for(int i = 0; i < 6; ++i) {
            long long x = (long long)v[i];
            for(int j = 0; j < 4; ++j) {
                long long y = (long long)v[adj[i][j]];
                long long z = (long long)v[adj[i][(j+1)%4]];
                if(y > z)
                    swap(y, z);
                long long s = x*(5*N*N - 8*N + 4) + 4*y*(2*N - 2) + 4*z;
                if(mn < 0 || mn > s)
                    mn = s;
            }
        }
        printf("%lld\n", mn);
    }

    return 0;
}