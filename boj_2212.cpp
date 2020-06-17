#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, K;
    scanf("%d %d", &N, &K);
    vector<int> v(N);
    for(int i = 0; i < N; ++i)
        scanf("%d", &v[i]);

    sort(v.begin(), v.end());

    vector<int> diff(N-1);
    for(int i = 0; i < N-1; ++i)
        diff[i] = v[i+1] - v[i];

    return 0;
}