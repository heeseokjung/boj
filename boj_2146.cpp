#include <cstdio>

int N;
int arr[100][100];
int visit[100][100];

int main() {
    scanf("%d", &N);
    for(int i = 0; i < N; ++i)
        for(int j = 0; j < N; ++j)
            scanf("%d", &arr[i][j]);

    // mult-src BFS?
    
    return 0;
}