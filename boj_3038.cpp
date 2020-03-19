#include <cstdio>

int N;
int copy[50000];
int tree[50000];

void copy_tree_to_left_subtree(int i, int j, int cur_depth, int max_depth) {
    if(cur_depth > max_depth)
        return;
    if(cur_depth == max_depth)
        tree[j] = 2*copy[i] + 1;
    else 
        tree[j] = 2*copy[i];
    copy_tree_to_left_subtree(i*2, j*2, cur_depth + 1, max_depth);
    copy_tree_to_left_subtree(i*2 + 1, j*2 + 1, cur_depth + 1, max_depth);
}

void copy_tree_to_right_subtree(int i, int j, int cur_depth, int max_depth) {
    if(cur_depth > max_depth)
        return;
    if(cur_depth == max_depth)
        tree[j] = 2*copy[i];
    else 
        tree[j] = 2*copy[i] + 1;
    copy_tree_to_right_subtree(i*2, j*2, cur_depth + 1, max_depth);
    copy_tree_to_right_subtree(i*2 + 1, j*2 + 1, cur_depth + 1, max_depth);
}

void print_answer(int i, int cur_depth, int max_depth) {
    if(cur_depth > max_depth)
        return;
    printf("%d ", tree[i]);
    print_answer(i*2, cur_depth + 1, max_depth);
    print_answer(i*2 + 1, cur_depth + 1, max_depth);
}

int main() {
    scanf("%d", &N);
    tree[1] = 1;
    for(int i = 1; i < N; ++i) {
        for(int j = 0; j < 50000; ++j)
            copy[j] = tree[j];
        copy_tree_to_left_subtree(1, 2, 0, i-1);
        copy_tree_to_right_subtree(1, 3, 0, i-1);
    }
    print_answer(1, 0, N-1);
    printf("\n");
    return 0;
}