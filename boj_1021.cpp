#include <cstdio>
#include <vector>
#include <deque>
using namespace std;

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    deque<int> dq;
    for(int i = 0; i < N; ++i)
        dq.push_back(i+1);
    vector<int> query(M);
    for(int i = 0; i < M; ++i)
        scanf("%d", &query[i]);
    int sum = 0;
    for(int i = 0; i < (int)query.size(); ++i) {
        int j = 0;
        while(dq[j] != query[i])
            ++j;
        if(j < (int)dq.size() - j) {
            for(int k = 0; k < j; ++k) {
                int tmp = dq.front();
                dq.pop_front();
                dq.push_back(tmp);
                ++sum;
            }
            dq.pop_front();
        }
        else {
            for(int k = (int)dq.size() - 1; k >= j; --k) {
                int tmp = dq.back();
                dq.pop_back();
                dq.push_front(tmp);
                ++sum;
            }
            dq.pop_front();
        }
    }
    printf("%d\n", sum);
    return 0;
}