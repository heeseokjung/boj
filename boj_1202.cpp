#include <cstdio>
#include <utility>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    int N, K;
    scanf("%d %d", &N, &K);
    vector<pair<int, int> > v(N);
    for(int i = 0; i < N; ++i)
        scanf("%d %d", &v[i].first, &v[i].second);
    vector<int> b(K);
    for(int i = 0; i < K; ++i)
        scanf("%d", &b[i]);

    sort(v.begin(), v.end());
    sort(b.begin(), b.end());

    long long sum = 0;
    priority_queue<int> pq;
    for(int i = 0, j = 0; i < K; ++i) {
        while(j < N && v[j].first <= b[i])
            pq.push(v[j++].second);
        if(!pq.empty()) {
            sum += (long long)pq.top();
            pq.pop();
        }
    }

    printf("%lld\n", sum);

    return 0;
}