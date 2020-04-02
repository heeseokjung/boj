#include <cstdio>
#include <vector>
using namespace std;

int N;
vector<int> v;
int pos[100001];

inline int absl(int x) {
    return x < 0 ? -x : x;
}

int main() {
    scanf("%d", &N);
    v = vector<int>(N);
    for(int i = 0; i < N; ++i)
        scanf("%d", &v[i]);
    for(int i = 0; i < N; ++i)
        pos[v[i]] = i;
    int i, j;
    for(i = 1, j = N; i < j; ++i, --j) {
        printf("%d\n", absl((i-1) - pos[i]));
        printf("%d\n", absl((j-1) - pos[j]));
    }
    if(N % 2)
        printf("%d\n", absl((i-1) - pos[i]));
    return 0;
}