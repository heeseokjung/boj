#include <cstdio>
#include <cstring>

int main() {
    int x, y, z;
    scanf("%d %d %d", &x, &y, &z);
    
    int sum[16001];
    memset(sum, 0, sizeof(sum));

    for(int i = 1; i <= x; ++i) {
        for(int j = 1; j <= y; ++j) {
            for(int k = 1; k <= z; ++k) {
                sum[i+j+k]++;
            }
        }
    }

    int mx = -1, idx = 3;
    for(int i = 3; i <= 16000; ++i) {
        if(mx < sum[i]) {
            mx = sum[i];
            idx = i;
        }
    }
    printf("%d\n", idx); 

    return 0;
}