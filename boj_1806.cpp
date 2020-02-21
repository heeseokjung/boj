#include <cstdio>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

int N, S;
int rsum[100001];
vector<int> v;
deque<int> dq;

int main() {
    scanf("%d %d", &N, &S);
    v = vector<int>(N+1);
    for(int i = 1; i <= N; ++i)
        scanf("%d", &v[i]);
    for(int i = 1; i <= N; ++i)
        rsum[i] = rsum[i-1] + v[i];
    int ans = N+1;
    for(int i = 1; i <= N; ++i) {
        dq.push_back(i);
        while(!dq.empty() && rsum[dq.back()] - rsum[dq.front()-1] >= S) {
            ans = min(ans, (int)dq.size());
            dq.pop_front();
        }
    }
    printf("%d\n", ans == N+1 ? 0 : ans);
    return 0;
}