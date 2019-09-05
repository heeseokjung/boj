#include <stdio.h>
#include <algorithm>
using namespace std;

int N, K;
typedef struct Country
{
    int cid;
    int num_gold;
    int num_silver;
    int num_bronze;
}Country;
Country countries[1000];

void input()
{
    scanf("%d %d", &N, &K);
    int x, y, z, w;
    for(int i = 0; i < N; ++i) {
        scanf("%d %d %d %d", &x, &y, &z, &w);
        countries[i].cid = x;
        countries[i].num_gold = y;
        countries[i].num_silver = z;
        countries[i].num_bronze = w;
    }
}

bool cmp(Country& c1, Country& c2)
{
    if(c1.num_gold > c2.num_gold) {
        return true;
    }
    else if(c1.num_gold < c2.num_gold) {
        return false;
    }
    else {
        if(c1.num_silver > c2.num_silver)
            return true;
        else if(c1.num_silver < c2.num_silver)
            return false;
        else
            return c1.num_bronze > c2.num_bronze;
    }
}

void run()
{
    sort(countries, countries + N, cmp);

    int i = 0;
    while(i < N && countries[i].cid != K)
        i++;
    int j = i - 1;
    while(j >= 0) {
        if(countries[j].num_gold == countries[i].num_gold &&
           countries[j].num_silver == countries[i].num_silver &&
           countries[j].num_bronze == countries[i].num_bronze)
               --j;
        else
            break;
    }
    printf("%d\n", j + 2);
}

int main()
{
    input();
    run();
    return 0;
}