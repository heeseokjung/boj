#include <stdio.h>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int a, b;
int idx, num;
vector<int> x_idx, x_num;
vector<int> y_idx, y_num;
vector<long long> y_sum;

void run();

int main()
{
    scanf("%d", &n);
    x_idx.reserve(n); x_num.reserve(n);
    for(int i = 0; i < n; ++i) {
        scanf("%d %d", &idx, &num);
        x_idx.push_back(idx);
        x_num.push_back(num);
    }
    scanf("%d", &m);
    y_idx.reserve(m); y_num.reserve(m); y_sum.resize(m+1); 
    for(int i = 0; i < m; ++i) {
        scanf("%d %d", &idx, &num);
        y_idx.push_back(idx);
        y_num.push_back(num);
        y_sum[i+1] = y_sum[i] + num;
    }
    scanf("%d %d", &a, &b);

    run();

    return 0;
}

void run()
{
    long long sum = 0;
    for(int i = 0; i < (int)x_idx.size(); ++i) {
        int start = lower_bound(y_idx.begin(), y_idx.end(), x_idx[i] + a) - y_idx.begin();
        int end = upper_bound(y_idx.begin(), y_idx.end(), x_idx[i] + b) - y_idx.begin();
        sum += x_num[i] * (y_sum[end] - y_sum[start]);
    }

    printf("%lld\n", sum);
}