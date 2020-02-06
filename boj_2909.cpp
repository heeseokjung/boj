#include <cstdio>

inline int pow(int x, int k) {
    int ret = 1;
    for(int i = 0; i < k; ++i)
        ret *= x;
    return ret;
}

int main() {
    int c, k;
    scanf("%d %d", &c, &k);
    int base = pow(10, k);
    int r = c % base;
    if(r < base -r)
        printf("%d\n", c - r);
    else 
        printf("%d\n", c + base - r);
    return 0;
}