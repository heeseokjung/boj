#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int N;
    scanf("%d", &N);
    if(N == 1) {
        printf("0\n");
        return 0;
    }
    priority_queue<int, vector<int>, greater<int> > pq;
    int x;
    for(int i = 0; i < N; ++i) {
        scanf("%d", &x);
        pq.push(x);
    }
    int sum = 0;
    int p[2];
    while(pq.size() >= 2) {
        p[0] = pq.top();
        pq.pop();
        p[1] = pq.top();
        pq.pop();
        sum += p[0] + p[1];
        pq.push(p[0] + p[1]);
    }
    printf("%d\n", sum);
    return 0;
}