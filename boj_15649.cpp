// boj_15649

#include <stdio.h>
#include <vector>
#include <iostream>

using namespace std;

int n, m;
bool valid[9];
vector<int> v;

void perm(int cnt)
{
    if(cnt == m) {
        for(int i = 0; i < v.size(); ++i)
            printf("%d ", v[i]);
        printf("\n");
        return;
    }
    for(int i = 1; i <= n; ++i) {
        if(!valid[i]) {
            valid[i] = true;
            v.push_back(i);
            perm(cnt + 1);
            valid[i] = false;
            v.pop_back();
        }
    }
}

int main()
{
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; ++i)
        valid[i] = false;

    perm(0);

    return 0;
}