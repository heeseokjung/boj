#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int GCD(int a, int b) {
    if(a < b) {
        int tmp = a;
        a = b;
        b = tmp;
    }
    while(a % b) {
        int tmp = a;
        a = b;
        b = tmp % b;
    }
    return b;
}

int main() {
    int N;
    scanf("%d", &N);
    vector<int> v(N);
    for(int i = 0; i < N; ++i)
        scanf("%d", &v[i]);
    sort(v.begin(), v.end());
    int gcd = v[1] - v[0];
    for(int i = 2; i < N; ++i) 
        gcd = GCD(gcd, v[i] - v[i-1]);
    set<int> s;
    for(int i = 2; i*i <= gcd; ++i) {
        if(gcd % i == 0) {
            s.insert(i);
            s.insert(gcd/i);
        }
    }
    s.insert(gcd);
    for(auto it = s.begin(); it != s.end(); ++it)
        printf("%d ", *it);
    printf("\n");
    return 0;
}