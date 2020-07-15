#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

inline int absl(int x) {
    return x < 0 ? -x : x;
}

int main() {
    int N;
    scanf("%d", &N);
    vector<int> v(N);
    for(int i = 0; i < N; ++i) 
        scanf("%d", &v[i]);

    sort(v.begin(), v.end());

    long long sum = 0;
    for(int i = 0, j = 1; i < N && j <= N; ++i, ++j)
        sum += (long long)absl(v[i] - j);

    printf("%lld\n", sum);

    return 0;
}