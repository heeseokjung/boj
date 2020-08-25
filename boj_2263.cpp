#include <cstdio>
#include <vector>
using namespace std;

int N;
vector<int> inorder, postorder;

void traversal(int a, int b, int c, int d) {
    if(a > b) 
        return;

    int root;
    for(int i = a; i <= b; ++i) {
        if(inorder[i] == postorder[d]) {
            root = i;
            break;
        }
    }

    printf("%d ", inorder[root]);

    int left = root - a;
    traversal(a, root-1, c, c+left-1);
    traversal(root+1, b, c+left, d-1);
}

int main() {
    scanf("%d", &N);
    inorder.assign(N, 0);
    for(int i = 0; i < N; ++i)
        scanf("%d", &inorder[i]);
    postorder.assign(N, 0);
    for(int i = 0; i < N; ++i)
        scanf("%d", &postorder[i]);

    traversal(0, N-1, 0, N-1);
    printf("\n");

    return 0;
}