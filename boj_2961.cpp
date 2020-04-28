#include <cstdio>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

inline int absl(int x) {
    return x < 0 ? -x : x;
}

int main() {
    int N;
    scanf("%d", &N);
    vector<pair<int, int> > v(N);
    for(int i = 0; i < N; ++i) 
        scanf("%d %d", &v[i].first, &v[i].second);

    int p = 1, mn = (int)1e9;
    while(p < (1<<N)) {
        int s = 1, b = 0;
        int pos = 0;
        while((1<<pos) <= p) {
            if((1<<pos) & p) {
                s *= v[pos].first;
                b += v[pos].second;
            }
            pos++;
        }
        mn = min(mn, absl(s - b));
        p++;
    }
    printf("%d\n", mn);

    return 0;
}