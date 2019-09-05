#include <stdio.h>

int n, s;
int seq[21];

void input()
{
    scanf("%d %d", &n, &s);
    for(int i = 0; i < n; ++i)
        scanf("%d", &seq[i]);
}

void run()
{
    int count = 0, sum = 0;
    int i = 1, j = 1, k = 0, end = 1 << n;
    while(i < end) {
        j = 1, k = 0;
        sum = 0;
        while(j < end) {
            if(i & j)
                sum += seq[k];
            j = j << 1;
            k++;
        }
        if(sum == s)
            count++;
        ++i;
    }

    printf("%d\n", count);
}

int main()
{
    input();
    run();
    return 0;
}