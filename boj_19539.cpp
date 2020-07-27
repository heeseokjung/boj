#include <cstdio>

int main() {
    int N;
    scanf("%d", &N);
    int sum = 0, count = 0;
    for(int i = 0; i < N; ++i) {
        int x;
        scanf("%d", &x);
        sum += x;
        count += x/2;
    }
    
    if(sum % 3 == 0) {
        if(sum/3 <= count)
            printf("YES\n");
        else
            printf("NO\n");
    } else {
        printf("NO\n");
    }

    return 0;
}