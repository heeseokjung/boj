#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> tree;

int main() {
    scanf("%d", &N);
    tree.reserve(N);
    int x;
    for(int i = 0; i < N; ++i) {
        scanf("%d", &x);
        tree.push_back(x);
    }
    sort(tree.begin(), tree.end());
    int mn = 1e9;
    for(int i = 0; i < N-1; ++i)
        mn = (tree[i+1] - tree[i] < mn) ? tree[i+1] - tree[i] : mn;
    while(true) {
        bool check = true;
        for(int i = 0, j; i < N-1; i++) {
            j = tree[i];
            while(j < tree[i+1])
                j += mn;
            if(j != tree[i+1]) {
                check = false;
                break;
            }
        }
        if(check)   
            break;
        mn--;
    }
    printf("%d\n", (tree[tree.size()-1] - tree[0])/mn + 1 - N);
    return 0;
}