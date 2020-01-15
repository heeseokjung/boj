#include <cstdio>

int N, M;
typedef struct Node {
    int id;
    int length;
    struct Node* parent;
}Node;
Node nodes[1000001];

int find(int x) {
    int y = x;
    while(nodes[x].parent != &nodes[x])
        x = nodes[x].parent->id;
    if(nodes[y].parent != &nodes[y])
        nodes[y].parent = &nodes[x];
    return x;
}

void Union(int x, int y) {
    int root_x = find(x);
    int root_y = find(y);
    if(root_x == root_y)
        return;
    if(nodes[root_x].length == nodes[root_y].length) {
        nodes[root_y].parent = &nodes[root_x];
        nodes[root_x].length++;
    }
    else if(nodes[root_x].length < nodes[root_y].length) {
        nodes[root_x].parent = &nodes[root_y];
    }
    else {
        nodes[root_y].parent = &nodes[root_x];
    }
}

int main() {
    scanf("%d %d", &N, &M);
    for(int i = 0; i <= N; ++i) {
        nodes[i].id = i;
        nodes[i].length = 1;
        nodes[i].parent = &nodes[i];
    }
    int op, x, y;
    for(int i = 0; i < M; ++i) {
        scanf("%d %d %d", &op, &x, &y);
        if(op) {
            if(find(x) == find(y))
                printf("YES\n");
            else
                printf("NO\n");
        }
        else {
            Union(x, y);
        }
    }
    return 0;
}