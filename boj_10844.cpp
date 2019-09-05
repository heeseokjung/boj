#include <stdio.h>

#define DIV 1000000000

long long num[10] = {0, };
long long prev_num[10] = {0, };

long long run(int n);

int main()
{
    int n;
    scanf("%d", &n);

    long long ans = run(n);
    printf("%lld\n", ans);

    return 0;
}

long long run(int n)
{
    if(n == 1)
        return 9;

    for(int i = 1; i <= 9; ++i) {
        num[i]++;
        prev_num[i]++;
    }

    for(int i = 2; i <= n; ++i) {
        for(int i = 0; i <= 9; ++i)
            num[i] = 0;
        
        for(int j = 0; j <= 9; ++j) {
            if(j == 0) {
                num[j + 1] = (num[j + 1] + prev_num[j]) % DIV;
            }
            else if(j == 9) {
                num[j - 1] = (num[j - 1] + prev_num[j]) % DIV;
            }
            else {
                num[j - 1] = (num[j - 1] + prev_num[j]) % DIV;
                num[j + 1] = (num[j + 1] + prev_num[j]) % DIV;
            }
        }

        for(int i = 0; i <= 9; ++i)
            prev_num[i] = num[i];
    }

    long long sum = 0;
    for(int i = 0; i <= 9; ++i)
        sum = (sum + num[i]) % DIV;

    return sum;
}