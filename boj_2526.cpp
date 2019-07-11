#include <stdio.h>

#define INVALID -1
int n, p;
int is_cycle[97];

void input()
{
    scanf("%d %d", &n, &p);
}

void run()
{
    for(int i = 0; i < 97; ++i)
        is_cycle[i] = INVALID;
    int nn = n;
    int ans, count = 1;
    while(true) {
        if(is_cycle[nn] != INVALID) {
            if(is_cycle[(nn*n)%p] != INVALID) {
                ans = count - is_cycle[nn];
                break;
            }
            else {
                count++;
                nn = (nn*n) % p;
                continue;
            }
        }
        is_cycle[nn] = count++;
        nn = (nn*n) % p;
    }
    printf("%d\n", ans);
}

int main()
{
    input();
    run();

    return 0;
}