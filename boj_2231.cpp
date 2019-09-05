#include <stdio.h>

int N;

void run()
{
    int i;
    for(i = 1; i < N; ++i) {
        int sum = i;
        int tmp = i;
        while(tmp) {
            sum += (tmp % 10);
            tmp /= 10;
        }

        if(sum == N)
            break;
    }

    if(i == N)
        printf("%d\n", 0);
    else
        printf("%d\n", i);
}

int main()
{
    scanf("%d", &N);

    run();

    return 0;
}