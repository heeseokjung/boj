#include <cstdio>
#include <vector>
using namespace std;

int N;
vector<int> v;
int pos[100001];
int tree[2000000];

int init_tree(int i, int j, int n) {
    if(i == j) {
        return tree[n] = 1;
    } else {
        int left = init_tree(i, (i + j)/2, n*2);
        int right = init_tree((i+j)/2 + 1, j, n*2 + 1);
        return tree[n] = left + right;
    }
}

int query(int i, int j, int l, int r, int n)
{
    if(i > r || j < l)
        return 0;
    if(l <= i && j <= r)
        return tree[n];
    return query(i, (i+j)/2, l, r, n*2) + query((i+j)/2 + 1, j, l, r, n*2 + 1);
}

void update_sum(int i, int j, int n, int idx, int diff)
{   
    if(idx < i || idx > j)
        return;
    tree[n] += diff;
    if(i != j) {
        update_sum(i, (i+j)/2, n*2, idx, diff);
        update_sum((i+j)/2 + 1, j, n*2 + 1, idx, diff);
    }
}

int main() {
    scanf("%d", &N);
    v = vector<int>(N);
    for(int i = 0; i < N; ++i)
        scanf("%d", &v[i]);
    for(int i = 0; i < N; ++i)
        pos[v[i]] = i;
    
    init_tree(0, N-1, 1);
    int i, j;
    for(i = 1, j = N; i < j; ++i, --j) {
        printf("%d\n", query(0, N-1, 0, pos[i], 1) - 1);
        update_sum(0, N-1, 1, pos[i], -1);
        printf("%d\n", query(0, N-1, pos[j], N-1, 1) - 1);
        update_sum(0, N-1, 1, pos[j], -1);
    }
    if(N % 2) {
        printf("%d\n", query(0, N-1, pos[i], N-1, 1) - 1);
        update_sum(0, N-1, 1, pos[i], -1);
    }
    return 0;
}