#include <stdio.h>

int n, mask;
int count = 0;

void dfs(int rw, int id, int dd)
{
    if(rw == mask) {
        count++;
        return;
    }
    int valid = mask & (~(rw | id | dd));
    while(valid) {
        int p = valid & -valid;
        valid -= p;
        dfs(rw | p, (id | p) >> 1, (dd | p) << 1);
    }
}

void run()
{
    scanf("%d", &n);
    mask = (1 << n) - 1;
    dfs(0, 0, 0);
    printf("%d\n", count);
}

int main()
{
    run();
    return 0;
}