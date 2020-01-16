#include <cstdio>
#include <algorithm>
using namespace std;

int N, M;
int ans = 0;
int tree[1000000];

void search(int i, int j) {
    while(i < j) {
        int m = (i+j)/2;
        int pos = lower_bound(tree, tree+N, m) - tree;
        long long sum = 0;
        for(int p = pos; p < N; ++p)
            sum += (tree[p] - m);
        if(sum >= (long long)M) {
            ans = (ans < m) ? m : ans;
            i = m+1;
        }
        else {
            j = m;
        }
    }
}

int main() {
    scanf("%d %d", &N, &M);
    int max_height = 0;
    for(int i = 0; i < N; ++i) {
        scanf("%d", tree+i);
        max_height = (max_height < tree[i]) ? tree[i] : max_height;
    }
    sort(tree, tree+N);
    search(0, max_height+1);
    printf("%d\n", ans);
    return 0;
}