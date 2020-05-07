#include <cstdio>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int TC;
    scanf("%d", &TC);
    while(TC--) {
        int N;
        scanf("%d", &N);
        vector<pair<int, int> > v(N+1);
        v[0].first = -1; v[0].second = 0;
        for(int i = 1, j; i <= N; ++i)
            scanf("%d %d", &v[i].first, &v[i].second);

        int M;
        scanf("%d", &M);
        vector<int> query(M);
        for(int i = 0; i < M; ++i)
            scanf("%d", &query[i]);

        sort(v.begin(), v.end());

        for(int i = 1; i <= N; ++i) {
            if(v[i].first != v[i-1].first && v[i].second != v[i-1].second) {
                int j = i, k = i;
                while(v[k].first == v[i].first)
                    k++;
                reverse(v.begin() + j, v.begin() + k);
            }
        }

        for(int i = 0; i < M; ++i) {
            int pos = query[i];
            printf("%d %d\n", v[pos].first, v[pos].second);
        }
    }
    return 0;
}