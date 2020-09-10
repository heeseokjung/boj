#include <cstdio>
#include <vector>
using namespace std;

int N;
vector<int> v;
int cache[50][2];
int sum = 0;

int main() {
    scanf("%d", &N);
    v.assign(N, 0);
    for(int i = 0; i < N; ++i) {
        scanf("%d", &v[i]);
        sum += v[i];
    }

    

    return 0;
}