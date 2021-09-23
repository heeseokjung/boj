#include <cstdio>
#include <algorithm>
using namespace std;

int memo[1000][1000];

int minimax(int *num, int s, int e, int d) {
    if(s > e)
        return 0;

    if(memo[s][e] > 0)
        return memo[s][e];
    
    if(d % 2)
        return memo[s][e] = min(minimax(num, s+1, e, d+1), 
                                minimax(num, s, e-1, d+1));
    else
        return memo[s][e] = max(minimax(num, s+1, e, d+1) + num[s], 
                                minimax(num, s, e-1, d+1) + num[e]); 
}

int main() {
    int TC;
    scanf("%d", &TC);

    while(TC--) {
        int N;
        int num[1000];
        scanf("%d", &N);
        for(int i = 0; i < N; ++i)
            scanf("%d", num+i);

        for(int i = 0; i < N; ++i)
            for(int j = 0; j < N; ++j)
                memo[i][j] = -1;

        printf("%d\n", minimax(num, 0, N-1, 0));
    }

    return 0;
}