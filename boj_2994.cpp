#include <cstdio>
#include <vector>
using namespace std;

int T, N;
vector<int> v;
int dp[5001][5001];
int group[5001];

int main() {
    int T, N;
    scanf("%d %d", &T, &N);
    vector<int> v(N+1);
    for(int i = 1; i <= N; ++i)
        scanf("%d", &v[i]);

    dp[0][0] = 1;
    for(int i = 1; i <= N; ++i) {
        for(int j = 0; j <= T; ++j) {
            if(dp[i-1][j])
                dp[i][j] = 1;
            if(j >= v[i] && dp[i-1][j-v[i]])
                dp[i][j] = 2;
        }
    }

    int t = T;
    while(!dp[N][t])
        t--;
    for(int i = N; i >= 1; --i) {
        group[i] = dp[i][t];
        if(group[i] == 2)
            t -= v[i];
    }

    int x = 0, y = 0;
    for(int i = 1; i <= N; ++i) {
        switch(group[i]) {
            case 1:
                printf("%d ", x);
                x += v[i];
                break;
            case 2:
                printf("%d ", y);
                y += v[i];
                break;
            default:
                break;
        }
    }
    printf("\n");

    return 0;
}