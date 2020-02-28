#include <cstdio>

int N;
int pos[1000001];
int neg[1000001];
#define MOD 1000000000

inline int abs(int x) {
    return x < 0 ? -x : x;
}

int fibonacci(int n) {
    if(n == 0)
        return 0;
    if(n == 1)
        return 1;
    if(n > 0 && pos[n] != MOD)
        return pos[n];
    if(n < 0 && neg[-n] != MOD)
        return neg[-n];
    if(n > 1) 
        return pos[n] = (fibonacci(n-1) + fibonacci(n-2)) % MOD;
    else
        return neg[-n] = (fibonacci(n+2) - fibonacci(n+1)) % MOD;
}

int main() {
    scanf("%d", &N);
    for(int i = 1; i <= abs(N); ++i)
        pos[i] = neg[i] = MOD;
    int f = fibonacci(N);
    if(f > 0)
        printf("1\n");
    else if(f < 0)
        printf("-1\n");
    else
        printf("0\n");
    printf("%d\n", abs(f));
    return 0;
}