#include <cstdio>
#include <vector>
using namespace std;

inline void swap(int& x, int& y) {
    int tmp = x;
    x = y;
    y = tmp;
}

int gcd(int x, int y) {
    if(x < y)
        swap(x, y);
    while(x % y) {
        int tmp = x;
        x = y;
        y = tmp % y;
    }
    return y;
}

int main() {
    int R, G;
    scanf("%d %d", &R, &G);
    
    int g = gcd(R, G);
    vector<int> v;
    for(int i = 1; i*i <= g; ++i) {
        if(g % i == 0) {
            printf("%d %d %d\n", i, R/i, G/i);
            if(g/i != i)
                v.push_back(g/i);
        }
    }

    for(int i = 0; i < (int)v.size(); ++i)
        printf("%d %d %d\n", v[i], R/v[i], G/v[i]);

    return 0;
}