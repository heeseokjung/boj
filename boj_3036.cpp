#include <cstdio>
#include <vector>
using namespace std;

inline void swap(int& a, int& b) {
    int tmp = a;
    a = b;
    b = tmp;
}

int gcd(int a, int b) {
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
    int N;
    scanf("%d", &N);
    vector<int> v(N);
    for(int i = 0; i < N; ++i)
        scanf("%d", &v[i]);
    int x = v[0];
    for(int i = 1; i < N; ++i) {
        int g = gcd(x, v[i]);
        printf("%d/%d\n", x/g, v[i]/g);
    }
    return 0;
}