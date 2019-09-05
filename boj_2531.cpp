#include <stdio.h>
using namespace std;

int n, d, k, c;
int sushi[30001];
int dup[3001] = {0, };
int max_num_kind = -1;

void input()
{
    scanf("%d %d %d %d", &n, &d, &k, &c);
    for(int i = 0; i < n; ++i)
        scanf("%d", &sushi[i]);
}

void run()
{
    input();

    int i, j, num_kind = 0;
    for(i = 0; i < k; ++i) {
        if(dup[sushi[i]] == 0)
            ++num_kind;
        ++dup[sushi[i]];
    }
    i = 0;
    j = k - 1;
    int cur_max;
    while(i < n) {
        cur_max = num_kind;
        if(dup[c] == 0)
            ++cur_max;
        if(cur_max > max_num_kind)
            max_num_kind = cur_max;
        if(--dup[sushi[i]] == 0)
            --num_kind;
        ++i; ++j;
        if(dup[sushi[j%n]] == 0)
            ++num_kind;
        ++dup[sushi[j%n]];
    }

    printf("%d\n", max_num_kind);
}

int main()
{
    run();
    return 0;
}