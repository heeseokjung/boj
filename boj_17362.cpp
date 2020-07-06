#include <cstdio>

int main() {
    int n;
    scanf("%d", &n);
    if((n + 7)%8 == 0 && (n + 7)/8 > 0)
        printf("1\n");
    else if((n + 6)%8 == 0 && (n + 6)/8 > 0 || n%8 ==0 && n/8 > 0)
        printf("2\n");
    else if((n + 1)%4 == 0 && (n + 1)/4 > 0)
        printf("3\n");
    else if((n + 4)% 8 == 0 && (n + 4)/8 > 0 || (n + 2)%8 == 0 && (n + 2)/8 > 0)
        printf("4\n");
    else
        printf("5\n");
    return 0;
}