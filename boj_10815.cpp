#include <cstdio>
#include <algorithm>
using namespace std;

int N, M;
int arr[500001];
int query[500001];

bool binsearch(int x) {
    int i = 0, j = N;
    while(i < j) {
        int m = (i+j)/2;
        if(arr[m] <= x) {
            if(arr[m] == x)
                return true;
            i = m+1;
        }
        else {
            j = m;
        }
    }
    return false;
}

int main() {
    scanf("%d", &N);
    for(int i = 0; i < N; ++i)
        scanf("%d", arr+i);
    scanf("%d", &M);
    for(int i = 0; i < M; ++i)
        scanf("%d", query+i);
    sort(arr, arr+N);
    for(int i = 0; i < M; ++i)
        printf("%d ", binsearch(query[i]) ? 1 : 0);
    printf("\n");
    return 0;
}