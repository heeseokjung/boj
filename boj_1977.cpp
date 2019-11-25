#include <cstdio>

int M, N;
bool is_square[10001];

int main() {
    scanf("%d %d", &M, &N);
    for(int i = 1; i*i <= N; ++i)
        is_square[i*i] = true;
    int min = -1, sum = 0;
    for(int i = M; i <= N; ++i) {
        if(is_square[i]) {
            min = (min < 0) ? i : min;
            sum += i;
        }
    }
    if(sum == 0)
        printf("-1\n");
    else
        printf("%d\n%d\n", sum, min);
    return 0;
}