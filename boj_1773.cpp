#include <cstdio>
#include <vector>
using namespace std;

inline void swap(int& x, int& y) {
    int tmp = x;
    x = y;
    y = tmp;
}

int GCD(int a, int b) {
    if(a < b)
        swap(a, b);
    while(a % b) {
        int tmp = a;
        a = b;
        b = tmp % b;
    }
    return b;
}

int main() {
    int N, C;
    scanf("%d %d", &N, &C);
    vector<int> v(N);
    for(int i = 0; i < N; ++i)
        scanf("%d", &v[i]);
    int gcd = v[0];
    for(int i = 1; i < N; ++i) 
        gcd = GCD(gcd, v[i]);
    long long lcm = 1;
    for(int i = 0; i < N; ++i)
        lcm = lcm * (long long)(v[i] / gcd);
    lcm = lcm * (long long)gcd;
    long long ans = 0;
    for(int i = 0; i < N; ++i) 
        ans += (long long)(C / v[i]);
    ans -= (((long long)C / lcm) * (long long)(N-1));
    printf("%lld\n", ans);
    return 0;
}