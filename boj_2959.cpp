#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
    int len[4];
    for(int i = 0; i < 4; ++i)
        scanf("%d", len+i);

    int mx = 0;
    for(int i = 0; i < 3; ++i) {
        for(int j = i+1; j < 4; ++j) {
            int h = 100;
            for(int k = 0; k < 4; ++k) {
                if(k != i && k != j && len[k] <= h)
                    h = len[k];
            }
            if(mx < h * min(len[i], len[j]))
                mx = h * min(len[i], len[j]);
        }
    }
    printf("%d\n", mx);
    
    return 0;
}