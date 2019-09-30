#include <stdio.h>

int main()
{
    int TC;
    char buf[50];
    scanf("%d", &TC); getchar();
    while(TC--) {
        fgets(buf, sizeof(buf), stdin);
        int size = 0;
        while(buf[size] != '\n')
            ++size;
        char c = '0';
        long long ans = 0;
        for(int i = 0; i < size; ++i) {
            if(buf[i] != c)
                ans += 1LL << (size - i - 1);
            c = (buf[i] != c) ? '1' : '0';
        }
        printf("%lld\n", ans);
    }
    return 0;
}