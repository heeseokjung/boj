#include <cstdio>
#include <algorithm>
using namespace std;

int N;
int a[4000];
int b[4000];
int c[4000];
int d[4000];
int ab[16000000];
int cd[16000000];

int search(int i, int j, int x) {
    int ret = j;
    int s = i, e = j;
    while(i < j) {
        int m = (i+j)/2;
        if(cd[m] >= x) {
            j = m;
            ret = (ret > m) ? m : ret;
        }
        else {
            i = m + 1;
        }
    }
    if(ret < s || ret >= e)
        return -1;
    return cd[ret] == x ? ret : -1;
}

int main() {
    scanf("%d", &N);
    for(int i = 0; i < N; ++i) 
        scanf("%d %d %d %d", a+i, b+i, c+i, d+i);
    for(int i = 0, p = 0, q = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            ab[p++] = a[i] + b[j];
            cd[q++] = c[i] + d[j];
        }
    }
    sort(cd, cd + N*N);
    long long ans = 0;
    for(int i = 0, j, k, pos; i < N*N; i = j) {
        long long x = 1, y = 1;
        for(j = i+1; j < N*N && ab[j] == ab[i]; ++j)
            x++;
        pos = search(0, N*N, -ab[i]);
        if(pos == -1)
            continue;
        for(k = pos+1; k < N*N && cd[k] == cd[pos]; ++k)
            y++;
        ans += x*y;
    }
    printf("%lld\n", ans);
    return 0;
}