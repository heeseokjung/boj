#include <stdio.h>

int n;
int count[10001] = {0, };

void input()
{
    scanf("%d", &n);
    int x;
    for(int i = 0; i < n; ++i) {
        scanf("%d", &x);
        count[x]++;
    }
}

void run()
{
    for(int i = 1; i <= 10000; ++i) {
        for(int j = 0; j < count[i]; ++j)
            printf("%d\n", i);
    }
}

int main()
{
    input();
    run();
    
    return 0;
}