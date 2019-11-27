#include <cstdio>
#include <vector>
using namespace std;

int TC, N, M;
int idx[200001];
int tree[1000000];

int init_tree(int i, int j, int n) {
    if(i == j) {
        tree[n] = (i < M+1) ? 0 : 1;
        return tree[n]; 
    }
    int m = (i + j)/2;
    return tree[n] = init_tree(i, m, n*2) + init_tree(m+1, j, n*2 + 1);
}

int range_sum(int i, int j, int p, int q, int n) {
    if(j < p || q < i)
        return 0;
    if(p <= i && j <= q)
        return tree[n];
    int m = (i + j)/2;
    return range_sum(i, m, p, q, n*2) + range_sum(m+1, j, p, q, n*2 + 1);
}

void update(int i, int j, int k, int n, int val) {
    if(k < i || j < k)
        return;
    tree[n] += val;
    if(i != j) {
        int m = (i + j)/2;
        update(i, m, k, n*2, val);
        update(m+1, j, k, n*2 + 1, val);
    }
}

int main() {
    scanf("%d", &TC);
    while(TC--) {
        scanf("%d %d", &N, &M);
        vector<int> query;
        query.reserve(M);
        int x;
        for(int i = 0; i < M; ++i) {
            scanf("%d", &x);
            query.push_back(x);
        }
        for(int i = 1; i <= N; ++i)
            idx[i] = M+i;
        init_tree(1, M+N, 1);
        int p = M;
        int size = (int)query.size();
        for(int i = 0; i < size; ++i) {
            printf("%d ", range_sum(1, M+N, 1, idx[query[i]] - 1, 1));
            update(1, M+N, idx[query[i]], 1, -1);
            idx[query[i]] = p--;
            update(1, M+N, idx[query[i]], 1, 1);
        }
        printf("\n");
    }
    return 0;
}