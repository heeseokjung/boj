#include <cstdio>

int N;
int A[500000];
int idx[1000001];
long long tree[1048576];

long long range_sum(int i, int j, int p, int q, int n) {
    if(i > q || j < p)
        return 0LL;
    if(p <= i && j <= q)
        return tree[n];
    int m = (i + j)/2;
    return range_sum(i, m, p, q, n*2) + range_sum(m+1, j, p, q, n*2 + 1);
}

void update(int i, int j, int n, int pos) {
    if(pos < i || pos > j)
        return;
    ++tree[n];
    if(i != j) {
        int m = (i + j)/2;
        update(i, m, n*2, pos);
        update(m+1, j, n*2 + 1, pos);
    }
}

int main() {
    scanf("%d", &N);
    for(int i = 0; i < N; ++i)
        scanf("%d", A+i);
    int x;  
    for(int i = 0; i < N; ++i) {
        scanf("%d", &x);
        idx[x] = i;
    }

    long long count = 0;
    for(int i = 0; i < N; ++i) {
        int pos = idx[A[i]];
        count += range_sum(0, N-1, pos+1, N-1, 1);
        update(0, N-1, 1, pos);
    }
    printf("%lld\n", count);
    return 0;
}