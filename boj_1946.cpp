#include <cstdio>
#include <vector>
using namespace std;

int main() {
    int TC;
    scanf("%d", &TC);
    while(TC--) {
        int N;
        scanf("%d", &N);
        vector<int> v1(N+1), v2(N+1);
        int x, y;
        for(int i = 0; i < N; ++i) {
            scanf("%d %d", &x, &y);
            v1[x] = i;
            v2[i] = y;
        }

        int count = 1, mn = v2[v1[1]];
        for(int i = 2; i <= N; ++i) {
            if(v2[v1[i]] < mn) {
                mn = v2[v1[i]];
                count++;
            }
        }

        printf("%d\n", count);
    }
    return 0;
}