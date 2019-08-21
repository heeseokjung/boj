#include <stdio.h>
#include <string.h>

int N;
char str[200010];
int RA[200010], tmpRA[200010];
int SA[200010], tmpSA[200010];
int cnt[200010];

void input()
{
    scanf("%d", &N);
    scanf("%s", str);
}

void counting_sort(int k)
{
    memset(cnt, 0, sizeof(cnt));
    for(int i = 0; i < N; ++i)
        cnt[SA[i] + k < N ? RA[SA[i] + k] : 0]++;
    int tmp, sum = 0, maxi = (N < 123) ? 123 : N;
    for(int i = 0; i < maxi; ++i) {
        tmp = cnt[i];
        cnt[i] = sum;
        sum += tmp;
    }
    for(int i = 0; i < N; ++i)
        tmpSA[cnt[SA[i] + k < N ? RA[SA[i] + k] : 0]++] = SA[i];
    for(int i = 0; i < N; ++i)
        SA[i] = tmpSA[i];
}

void buildSA()
{
    for(int i = 0; i < N; ++i) {
        SA[i] = i;
        RA[i] = str[i];
    }
    for(int k = 1; k < N; k <<= 1) {
        counting_sort(k);
        counting_sort(0);
        int rank = 0;
        tmpRA[SA[0]] = rank;
        for(int i = 1; i < N; ++i) 
            tmpRA[SA[i]] = (RA[SA[i]] == RA[SA[i-1]] && RA[SA[i]+k] == RA[SA[i-1]+k]) ? rank : ++rank;
        for(int i = 0; i < N; ++i)
            RA[i] = tmpRA[i];
        if(RA[SA[N-1]] == N-1)
            break;
    }
}

void run()
{
    buildSA();
}

int main()
{
    input();
    run();
}