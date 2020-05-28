#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    scanf("%d", &N);
    vector<int> v(N);
    for(int i = 0; i < N; ++i) 
        scanf("%d", &v[i]);

    vector<int> lis;
    for(int i = 0; i < N; ++i) {
        int size = (int)lis.size();
        if(size == 0 || lis[size-1] < v[i]) {
            lis.push_back(v[i]);
        } else {
            auto it = lower_bound(lis.begin(), lis.end(), v[i]);
            *it = v[i];
        }
    }

    printf("%d\n", (int)lis.size());

    return 0;
}