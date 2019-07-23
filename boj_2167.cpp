#include <stdio.h>
#include <utility>
#include <vector>
using namespace std;

int n, m, k;
int arr[301][301] = {0, };
int rsum[301][301] = {0, };
typedef pair<int, int> ii;
vector<pair<ii, ii> > query;

void input()
{
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            scanf("%d", &arr[i][j]);
        }
    }
    scanf("%d", &k);
    query.reserve(k);
    int p, q, x, y;
    for(int i = 0; i < k; ++i) {
        scanf("%d %d %d %d", &p, &q, &x, &y);
        query.push_back(make_pair(pair<int, int>(p, q), pair<int, int>(x, y)));
    }
}

void run()
{
    int sum;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            rsum[i][j] = rsum[i][j-1] + arr[i][j];
        }
    }
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            rsum[i][j] += rsum[i-1][j];
        }
    }

    for(int i = 0; i < k; ++i) {
        pair<int, int> p = query[i].first;
        pair<int, int> q = query[i].second;
        int ans = rsum[q.first][q.second] - rsum[p.first-1][q.second] - rsum[q.first][p.second-1] +
                  rsum[p.first-1][p.second-1];
        printf("%d\n", ans);
    }
}

int main()
{
    input();
    run();
    return 0;
}