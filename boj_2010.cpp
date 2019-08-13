#include <stdio.h>

int N;
int multitap[500000];

void input()
{
    scanf("%d", &N);
    for(int i = 0; i < N; ++i)
        scanf("%d", multitap + i);
}

void run()
{
    int num_plug = multitap[0];
    for(int i = 1; i < N; ++i) {
        --num_plug;
        num_plug += multitap[i];
    }
    printf("%d\n", num_plug);
}

int main()
{
    input();
    run();
    return 0;
}