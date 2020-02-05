#include <cstdio>

int main() {
    int e, f, c;
    scanf("%d %d %d", &e, &f, &c);
    int x = e + f;
    int ans = 0;
    while(x >= c) {
        x -= c;
        ans++;
        ++x;
    }
    printf("%d\n", ans);
    return 0;
}