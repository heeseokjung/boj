#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    int arr[100000][3];
    scanf("%d", &N);
    for(int i = 0; i < N; ++i)
        scanf("%d %d %d", &arr[i][0], &arr[i][1], &arr[i][2]);

    vector<vector<int> > dp_max(2, vector<int>(3, 0));
    vector<vector<int> > dp_min(2, vector<int>(3, 0));
    for(int i = 0; i < 3; ++i)
        dp_min[0][i] = dp_max[0][i] = arr[0][i];
    for(int i = 1; i < N; ++i) {
        dp_max[1][0] = max(dp_max[0][0], dp_max[0][1]) + arr[i][0];
        dp_max[1][1] = max(max(dp_max[0][0], dp_max[0][1]), dp_max[0][2]) + arr[i][1];
        dp_max[1][2] = max(dp_max[0][1], dp_max[0][2]) + arr[i][2];

        dp_min[1][0] = min(dp_min[0][0], dp_min[0][1]) + arr[i][0];
        dp_min[1][1] = min(min(dp_min[0][0], dp_min[0][1]), dp_min[0][2]) + arr[i][1];
        dp_min[1][2] = min(dp_min[0][1], dp_min[0][2]) + arr[i][2];

        for(int j = 0; j < 3; ++j) {
            dp_max[0][j] = dp_max[1][j];
            dp_min[0][j] = dp_min[1][j];
        }
    }

    int mx = -1, mn = 1000000;
    if(N == 1) {
        mx = max(max(dp_max[0][0], dp_max[0][1]), dp_max[0][2]);
        mn = min(min(dp_min[0][0], dp_min[0][1]), dp_min[0][2]);
    } else {
        for(int i = 0; i < 3; ++i) {
            mx = mx < dp_max[1][i] ? dp_max[1][i] : mx;
            mn = mn > dp_min[1][i] ? dp_min[1][i] : mn;
        }
    }
    printf("%d %d\n", mx, mn);

    return 0;
}