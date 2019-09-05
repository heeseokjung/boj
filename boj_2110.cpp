#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int N, C;
vector<int> v;
int ans = 2e9;

void input()
{
    scanf("%d %d", &N, &C);
    v.reserve(N);
    for(int i = 0, j; i < N; ++i) {
        scanf("%d", &j);
        v.push_back(j);
    }
}

void run()
{
    sort(v.begin(), v.end());
    int i = 1, j = v.back() - v.front() + 1;
    while(i < j) {
        int m = (i + j) / 2;
        int p = 0, cnt = 1;
        for(int k = 0; k < (int)v.size(); ++k) {
            if(v[k] - v[p] >= m) {
                ++cnt;
                p = k;
            }
        }
        if(cnt >= C) {
            ans = m;
            i = m + 1;
        } else {
            j = m;
        }
    }
    printf("%d\n", ans);
}

int main()
{
    input();
    run();
    return 0;
}