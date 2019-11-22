#include <cstdio>

int run(int x) {
    int p = x%10, count = 0, max = 1;
    while(x) {
        if(p == x%10) {
            count++;
        }
        else {
            p = x%10;
            max = (max < count) ? count : max;
            count = 1;
        }
        x /= 10;
    }
    if(count > 0)
        max = (max < count) ? count : max;
    return max;
}

int main() {
    int A, B, C;
    scanf("%d %d %d", &A, &B, &C);
    printf("%d\n", run(A));
    printf("%d\n", run(B));
    printf("%d\n", run(C));
}