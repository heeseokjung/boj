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
    int s[20][20];
    for(int i = 0; i < N; ++i)
        for(int j = 0; j < N; ++j)
            scanf("%d", &s[i][j]);

    int p = 1, mn = (int)1e9;
    while(p < (1<<N)) {
        int count = 0;
        for(int i = 0; i < N; ++i) {
            if(p & (1<<i))
                count++;
        }

        if(count != N/ 2) {
            p++;
            continue;
        }

        vector<int> v1, v2;
        for(int i = 0; i < N; ++i) {
            if(p & (1<<i))
                v1.push_back(i);
            else
                v2.push_back(i);
        }

        int v1_sum = 0, v2_sum = 0;
        for(int i = 0; i < N/2; ++i) {
            for(int j = 0; j < N/2; ++j) {
                v1_sum += s[v1[i]][v1[j]];
            }
        }
        for(int i = 0; i < N/2; ++i) {
            for(int j = 0; j < N/2; ++j) {
                v2_sum += s[v2[i]][v2[j]];
            }
        }

        mn = min(mn, absl(v1_sum - v2_sum));
        p++;
    }

    printf("%d\n", mn);

    return 0;
}