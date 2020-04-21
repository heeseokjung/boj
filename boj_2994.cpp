#include <cstdio>
#include <vector>
using namespace std;

int main() {
    int T, N;
    scanf("%d %d", &T, &N);
    vector<int> v(N);
    for(int i = 0; i < N; ++i)
        scanf("%d", &v[i]);
    return 0;
}