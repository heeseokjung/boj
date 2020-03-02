#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    scanf("%d", &N);
    vector<int> v(N);
    for(int i = 0; i < N; ++i)
        scanf("%d", &v[i]);
    int ans = 0;
    for(int i = 0; i < N; ++i) {
        int j = i;
        while(j+1 < N && v[j] < v[j+1])
            j++;
        ans = max(ans, v[j] - v[i]);
    }
    printf("%d\n", ans);
    return 0;
}