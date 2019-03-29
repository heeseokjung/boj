// boj_154650

#include <stdio.h>
#include <vector>

using namespace std;

int n, m;
bool visit[9];
vector<int> v;

void comb(int cnt, int cur)
{
    if(cnt == m) {
        for(int i = 0; i < v.size(); ++i) 
            printf("%d ", v[i]);
        printf("\n");
        return;
    }
    for(int i = cur; i <= n; ++i) {
        if(!visit[i]) {
            visit[i] = true;
            v.push_back(i);
            comb(cnt + 1, i);
            v.pop_back();
            visit[i] = false;
        }
    }
}

int main()
{
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; ++i)
        visit[i] = false;

    comb(0, 1);
}