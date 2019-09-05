#include <stdio.h>
#include <vector>
using namespace std;

int tc;
int a, b, r;
vector<int> r_table[10];

void build_table()
{
    for(int i = 2; i < 10; ++i) {
        r_table[i].push_back(i);
        int j = i * i;
        while(j % 10 != i) {
            r_table[i].push_back(j % 10);
            j = j * i;
        }
    }
}

void run()
{
    build_table();
    
    scanf("%d", &tc);
    while(tc--) {
        scanf("%d %d", &a, &b);
        r = a % 10;
        if(r == 0 || r == 1) {
            printf("%d\n", (r == 0) ? 10 : 1);
            continue;
        }
        int s = (int)r_table[r].size();
        int ans = (b % s) - 1;
        if(ans < 0)
            ans = s - 1;
        printf("%d\n", r_table[r][ans]);
    }
}

int main()
{
    run();
    return 0;
}