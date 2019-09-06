#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, K;
int seq[501];

void run()
{
    scanf("%d %d %d", &N, &M, &K);
    if(M + K - 1 <= N && N <= M*K) {
        for(int i = 0; i < N; ++i)
            seq[i] = i + 1;
        vector<int> v (M, 0);
        v[M-1] = K;
        int x = K;
        while(x < N) {
            for(int i = M - 2; i >= 0 && x < N; --i, ++x)
                ++v[i];
        }
        for(int i = 0, p = 0; i < M; ++i) {
            reverse(seq + p, seq + p + v[i]);
            p += v[i];
        }
        for(int i = 0; i < N; ++i)
            printf("%d ", seq[i]);
        printf("\n");
    } else {
        printf("-1\n");
    }
}

int main()
{
    run();
    return 0;
}