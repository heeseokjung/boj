#include <cstdio>
#include <deque>
#include <utility>
using namespace std;

int N, L;
int arr[5000000];

int main() {
    scanf("%d %d", &N, &L);
    for(int i = 0; i < N; ++i)
        scanf("%d", arr+i);
    deque<pair<int, int> > dq;
    for(int i = 0, j; i < N; ++i) {
        j = (i-L+1 < 0) ? 0 : i-L+1;
        while(!dq.empty() && dq.front().second < j)
            dq.pop_front();
        while(!dq.empty() && dq.back().first > arr[i])
            dq.pop_back();
        dq.push_back(pair<int, int>(arr[i], i));
        printf("%d ", dq.front().first);
    }
    printf("\n");
    return 0;
}