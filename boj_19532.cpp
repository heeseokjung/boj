#include <cstdio>

int main() {
    int a, b, c, d, e, f;
    scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f);
    int det = a*e - b*d;
    int x = (e*c - b*f)/det;
    int y = (a*f - c*d)/det;
    printf("%d %d\n", x, y);
    return 0;
}