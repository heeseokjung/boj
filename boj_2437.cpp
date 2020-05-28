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

    sort(v.begin(), v.end());

    int sum = 0;
    for(int i = 0; i < N; ++i) {
        if(sum + 1 < v[i])
            break;
        sum += v[i];
    }
    printf("%d\n", sum + 1);

    return 0;
}