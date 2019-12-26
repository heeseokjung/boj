#include <cstdio>

int main() {
    int a, b, v;
    scanf("%d %d %d", &a, &b, &v);
    int net = a - b;
    int ans = (v-b)/net + ((v-b)%net ? 1 : 0);
    printf("%d\n", ans);
    return 0;
}