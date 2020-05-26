#include <cstdio>

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    int cost1 = 10000, cost6 = 10000;
    for(int i = 0; i < M; ++i) {
        int x, y;
        scanf("%d %d", &x, &y);
        cost6 = (cost6 > x ? x : cost6);
        cost1 = (cost1 > y ? y : cost1);
    }

    if(cost1 * 6 < cost6) {
        printf("%d\n", cost1 * N);
    } else {
        int sum = cost6 * (N / 6);
        if(N % 6) {
            if((N % 6)*cost1 < cost6)
                sum += (N % 6)*cost1;
            else
                sum += cost6;
        }
        printf("%d\n", sum);
    }
    
    return 0;
}