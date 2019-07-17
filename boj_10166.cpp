#include <stdio.h>

int r1, r2;
int seat_used = 0;
bool degree[2001][2001] = {false, };

void input()
{
    scanf("%d %d", &r1, &r2);
}

inline int gcd(int x, int y)
{
    if(x < y) {
        int tmp = x;
        x = y;
        y = tmp;
    }
    int r;
    while(y != 0) {
        r = x % y;
        x = y;
        y = r;
    } 
    return x;
}

void run()
{
    for(int i = r1; i <= r2; ++i) {
        for(int j = 0; j < i; ++j) {
            int g = gcd(i, j);
            if(!degree[i/g][j/g]) {
                degree[i/g][j/g] = true;
                ++seat_used;
            }
        }
    }
    printf("%d\n", seat_used);
}

int main()
{
    input();
    run();
    return 0;
}