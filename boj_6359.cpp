#include <stdio.h>

int main() {
    int TC, N;
    int door[101];
    scanf("%d", &TC);
    while(TC--) {
        scanf("%d", &N);
        for(int i = 1; i <= N; ++i)
            door[i] = 1;
        for(int i = 1; i <= N; ++i) {
            for(int j = 1; i*j <= N; ++j)
                door[i*j] = 1 - door[i*j];
        }
        int count = 0;
        for(int i = 1; i <= N; ++i) {
            if(!door[i])
                count++;
        }
        printf("%d\n", count);
    }
    return 0;
}