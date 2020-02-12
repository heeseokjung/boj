#include <cstdio>
#include <vector>
using namespace std;

int N, C;
bool check[2000001];

int main() {
    scanf("%d %d", &N, &C);
    vector<int> v(N);
    for(int i = 0; i < N; ++i)
        scanf("%d", &v[i]);
    int count = 0;
    for(int i = 0; i < N; ++i) {
        for(int j = 1; v[i]*j <= C; ++j) {
            if(!check[v[i]*j]) {
                check[v[i]*j] = true;
                count++;
            }
        }
    }
    printf("%d\n", count);
    return 0;
}