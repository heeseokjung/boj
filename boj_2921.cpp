#include <cstdio>

int N;
bool check[1001][1001];

int main() {
    scanf("%d", &N);
    int sum = 0;
    for(int i = 0; i <= N; ++i) {
        for(int j = 0; j <= N; ++j) {
            if(!check[i][j]) {
                sum += i + j;
                check[i][j] = true;
                check[j][i] = true;
            }
        }
    }
    printf("%d\n", sum);
    return 0;
}