#include <cstdio>
#include <cmath>

int main() {
    int N, W, H;
    scanf("%d %d %d", &N, &W, &H);
    for(int i = 0; i < N; ++i) {
        int x;
        scanf("%d", &x);
        if(x <= W || x <= H || x <= sqrt(W*W + H*H))
            printf("DA\n");
        else
            printf("NE\n");
    }
    return 0;
}