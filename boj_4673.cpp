#include <stdio.h>

bool check[10001] = {false, };

void run()
{
    for(int i = 1; i <= 10000; ++i) {
        int j = i, sum = i;
        while(j != 0) {
            sum += j % 10;
            j = j / 10;
        }
        if(sum <= 10000)
            check[sum] = true;
    }

    for(int i = 1; i <= 10000; ++i) {
        if(!check[i])
            printf("%d\n", i);
    }
}

int main()
{
    run();
    return 0;
}