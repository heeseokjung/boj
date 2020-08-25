#include <cstdio>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int main() {
    int N;
    scanf("%d", &N);
    vector<int> v(N);
    for(int i = 0; i < N; ++i)
        scanf("%d", &v[i]);

    vector<int> lis, p(N);
    for(int i = 0; i < N; ++i) {
        if(lis.empty() || lis.back() < v[i]) {
            lis.push_back(v[i]);
            p[i] = (int)lis.size()-1;
        } else {
            auto it = lower_bound(lis.begin(), lis.end(), v[i]);
            *it = v[i];
            p[i] = (int)(it - lis.begin());
        }
    }

    stack<int> s;
    int len = (int)lis.size();
    for(int i = N-1; i >= 0; --i) {
        if(p[i] == len-1) {
            s.push(v[i]);
            len--;
        }
    }

    printf("%d\n", (int)lis.size());
    while(!s.empty()) {
        printf("%d ", s.top());
        s.pop();
    }
    printf("\n");

    return 0;
}