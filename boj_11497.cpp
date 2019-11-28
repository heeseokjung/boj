#include <cstdio>
#include <deque>
#include <algorithm>
using namespace std;

int N;
int arr[10000];

int main() {
    int TC;
    scanf("%d", &TC);
    while(TC--) {
        scanf("%d", &N);
        for(int i = 0; i < N; ++i)
            scanf("%d", arr+i);
        sort(arr, arr+N);
        deque <int> dq;
        dq.push_back(arr[N-1]);
        dq.push_back(arr[N-2]);
        dq.push_front(arr[N-3]);
        int ans = max(arr[N-1] - arr[N-2], arr[N-1] - arr[N-3]);
        int m1, m2;
        for(int i = N-4; i > 0; i -= 2) {
            m1 = max(dq.front() - arr[i], dq.back() - arr[i-1]);
            m2 = max(dq.front() - arr[i-1], dq.back() - arr[i]);
            if(m1 < m2) {
                dq.push_front(arr[i]);
                dq.push_back(arr[i-1]);
                ans = (ans < m1) ? m1 : ans;
            }
            else {
                dq.push_front(arr[i-1]);
                dq.push_back(arr[i]);
                ans = (ans < m2) ? m2 : ans;
            }
        }
        if(dq.size() < N) {
            int m = max(dq.front() - arr[0], dq.back() - arr[0]);
            ans = (ans < m) ? m : ans;
        }
        printf("%d\n", ans);
    }
    return 0;
}