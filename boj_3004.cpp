#include <cstdio>

int main() {
    int N;
    scanf("%d", &N);
    int w = N/2;
    int h = N - w;
    printf("%d\n", (w + 1)*(h + 1));
    return 0;
}