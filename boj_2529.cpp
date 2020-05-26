#include <cstdio>

int main() {
    int k;
    char ineq[10];
    scanf("%d", &k);
    getchar();
    for(int i = 0; i < k; ++i) {
        scanf("%c", ineq+i);
        getchar();
    }

    int x = 9, y = 0;
    for(int i = 0; i < k; ++i) {
        if(ineq[i] == '>') {
            for(int j = x-y; j <= x; ++j)
                printf("%d", j);
            x = x - y - 1;
            y = 0;
        } else {
            y++;
        }
    }
    for(int i = x-y; i <= x; ++i)
        printf("%d", i);
    printf("\n");

    x = 0, y = 0;
    for(int i = 0; i < k; ++i) {
        if(ineq[i] == '<') {
            for(int j = x+y; j >= x; --j)
                printf("%d", j);
            x = x + y + 1;
            y = 0;
        } else {
            y++;
        }
    }
    for(int i = x+y; i >= x; --i)
        printf("%d", i);
    printf("\n");

    return 0;
}