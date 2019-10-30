#include <stdio.h>

inline void swap(int& x, int& y) {
    int tmp = x;
    x = y;
    y = tmp;
}

int gcd(int x, int y) {
    if(x < y)
        swap(x, y);
    while(y > 0) {
        int tmp = x;
        x = y;
        y = tmp % x;
    }
    return x;
}

int main() {
    int G, L;
    scanf("%d %d", &G, &L);
    int Q = L/G, x = 1;
    for(int i = 2; i*i <= Q; ++i) {
        if(Q % i == 0 && gcd(i, Q/i) == 1)
            x = i;
    }
    printf("%d %d\n", x*G, (Q/x)*G);
    return 0;
}