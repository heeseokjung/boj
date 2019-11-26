#include <cstdio>

int N;
long long day[1000000];
long long max[1000000];

int main() {
    int TC;
    scanf("%d", &TC);
    while(TC--) {
        scanf("%d", &N);
        for(int i = 0; i < N; ++i)
            scanf("%lld", day+i);
        long long tmp = -1;
        for(int i = N-1; i >= 0; --i) {
            tmp = (tmp < day[i]) ? day[i] : tmp;
            max[i] = tmp;
        }
        long long sum = 0;
        for(int i = 0; i < N; ++i) 
            sum += (max[i] - day[i]);
        printf("%lld\n", sum);
    }
    return 0;
}