#include <stdio.h>

int n;

void input()
{
    scanf("%d", &n);
}

void run()
{
    int count = 0;
    int tmp, x, y;
    tmp = n;
    while(true) {
        count++;
        y = tmp % 10;
        tmp = tmp / 10;
        x = tmp % 10;
        tmp = y*10 + (x + y)%10;
        if(tmp == n)
            break;
    }

    printf("%d\n", count);
}

int main()
{
    input();
    run();

    return 0;
}