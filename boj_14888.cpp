#include <stdio.h>

int N;
int arr[11];
int min = 2e9, max = -2e9;

void run(int i, int result, int add, int sub, int mul, int div) {
    if(i == N-1) {
        min = (result < min) ? result : min;
        max = (result > max) ? result : max;
        return;
    }
    if(add > 0)
        run(i+1, result + arr[i+1], add-1, sub, mul, div);
    if(sub > 0)
        run(i+1, result - arr[i+1], add, sub-1, mul, div);
    if(mul > 0)
        run(i+1, result * arr[i+1], add, sub, mul-1, div);
    if(div > 0)
        run(i+1, result / arr[i+1], add, sub, mul, div-1);
}

int main() {
    scanf("%d", &N);
    for(int i = 0; i < N; ++i)
        scanf("%d", arr+i);
    int add, sub, mul, div;
    scanf("%d %d %d %d", &add, &sub, &mul, &div);
    run(0, arr[0], add, sub, mul, div);
    printf("%d\n%d\n", max, min);
    return 0;
}