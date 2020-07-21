#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int N;
    scanf("%d", &N);
    if(N >= 1023) {
        printf("-1\n");
        return 0;
    }

    vector<long long> v(1023);
    queue<long long> q;
    int idx;
    for(idx = 1; idx < 10; ++idx) {
        q.push((long long)idx);
        v[idx] = idx;
    }

    while(!q.empty() && idx <= N) {
        long long num = q.front(); q.pop();
        int lsd = num % 10LL;
        for(int i = 0; i < lsd; ++i) {
            q.push(num*10LL + (long long)i);
            v[idx++] = num*10LL + (long long)i;
        }
    }
    
    printf("%lld\n", v[N]);
     
    return 0;
}