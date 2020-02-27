#include <cstdio>
#include <set>
using namespace std;

int N, M;
set<int> s;

int main() {
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; ++i) {
        int x;
        scanf("%d", &x);
        s.insert(x);
    }
    int count = 0;
    for(int i = 0; i < M; ++i) {
        int x;
        scanf("%d", &x);
        if(s.find(x) != s.end())
            count++;
    } 
    printf("%d\n", (N-count) + (M-count));
    return 0;
}