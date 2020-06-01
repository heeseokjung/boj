#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, L;
    scanf("%d %d", &N, &L);
    vector<float> v(N);
    for(int i = 0; i < N; ++i)
        scanf("%f", &v[i]);

    sort(v.begin(), v.end());

    int count = 0;
    float cover = 0;
    for(int i = 0; i < N; ++i) {
        if(v[i] + 0.5f > cover) {
            count++;
            cover = v[i] + (float)L - 0.5f;
        }
    }

    printf("%d\n", count);

    return 0;
}