#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int k, size;
int tree[1<<21], subtree[1<<21];

int main() {
    scanf("%d", &k);
    for(int i = 0, j = 2; i < (1 << (k+1))-2; ++i, ++j)
        scanf("%d", tree+j);
    
    int sum = 0;
    for(int i = (1 << (k+1)) - 1; i > 1; i -= 2) {
        int r = subtree[i] + tree[i];
        int l = subtree[i-1] + tree[i-1];
        subtree[i/2] = max(r, l);
        int diff = abs(r-l);
        sum += tree[i] + tree[i-1] + diff;
    }

    printf("%d\n", sum);

    return 0;
}