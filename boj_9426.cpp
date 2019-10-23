#include <stdio.h>
#define RMAX 65535

int N, K;
int temp[250010];
int tree[150000];

void update(int i, int j, int n, int num, int type) {
    if(i == j) {
        tree[n] += type;
        return;
    }
    int m = (i+j)/2;
    if(m < num)
        update(m+1, j, n*2 + 1, num, type);
    else
        update(i, m, n*2, num, type);
    tree[n] += type;
}

int find_median(int i, int j, int n, int k) {
    if(i == j)
        return i;
    int m = (i+j)/2;
    if(tree[n*2] < k)
        return find_median(m+1, j, n*2 + 1, k - tree[n*2]);
    else
        return find_median(i, m, n*2, k);
}

int main() {
    scanf("%d %d", &N, &K);
    for(int i = 0; i < N; ++i)
        scanf("%d", temp + i);

    for(int i = 0; i < K; ++i) 
        update(0, RMAX, 1, temp[i], 1);
    int mid = (1+K)/2;
    long long sum = 0;
    for(int i = 0; i < N-K+1; ++i) {
        sum += (long long)find_median(0, RMAX, 1, mid);
        update(0, RMAX, 1, temp[i], -1);
        update(0, RMAX, 1, temp[i+K], 1);
    }
    printf("%lld\n", sum);
    return 0;
}