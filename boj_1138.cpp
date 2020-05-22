#include <cstdio>
#include <vector>
using namespace std;

int main() {
    int N;
    scanf("%d", &N);
    vector<int> v(N+1);
    for(int i = 1; i <= N; ++i)
        scanf("%d", &v[i]);

    vector<int> check(N+1, 0);
    for(int i = 1; i <= N; ++i) {
        int count = 0;
        for(int j = 1; j <= N; ++j) {
            if(check[j] == 0) {
                if(count == v[i]) {
                    check[j] = i;
                    break;
                } else {
                    count++;
                }
            }
        }
    }

    for(int i = 1; i <= N; ++i)
        printf("%d ", check[i]);
    printf("\n");
    
    return 0;
}