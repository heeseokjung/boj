#include <stdio.h>
#include <utility>
using namespace std;

int n, m, k;
int arr[16][16];
long long dp[16][16];

void input()
{
    scanf("%d %d %d", &n, &m, &k);
}

long long find_num_path(pair<int, int> src, pair<int, int> dest)
{
    if(dest.first < src.first || dest.second < src.second) {
        return 0;
    }
    if(dp[dest.first][dest.second] != -1 || src == dest) {
        return dp[dest.first][dest.second];
    }
    return dp[dest.first][dest.second] =
           find_num_path(src, pair<int, int>(dest.first - 1, dest.second)) +
           find_num_path(src, pair<int, int>(dest.first, dest.second - 1));
}

void run()
{
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            dp[i][j] = -1;
        }
    }
    dp[1][1] = 1;

    long long ans;
    if(k) {
        pair<int, int> kp((k%m) ? k/m + 1 : k/m, (k%m) ? k%m : m);
        ans = find_num_path(pair<int, int>(1, 1), kp);
        dp[kp.first][kp.second] = 1;
        ans = ans * find_num_path(kp, pair<int, int>(n, m));
    }
    else {
        ans = find_num_path(pair<int, int>(1, 1), pair<int, int>(n, m));
    }
    printf("%lld\n", ans);
}

int main()
{
    input();
    run();
    return 0;
}