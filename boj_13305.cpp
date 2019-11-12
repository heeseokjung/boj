#include <stdio.h>

int N;
int node[100000];
int edge[100000];

int main() {
    scanf("%d", &N);
    for(int i = 0; i < N-1; ++i)
        scanf("%d", edge + i);
    for(int i = 0; i < N; ++i)
        scanf("%d", node + i);
    long long cost = 0;
    for(int i = 0, j = 0; i < N-1;) {
        long long dist = 0;
        while(j < N-1 && node[i] <= node[j]) {
            dist += (long long)edge[j];
            j++;
        }
        cost += (long long)node[i] * dist;
        i = j;
    }
    printf("%lld\n", cost);
    return 0;
}