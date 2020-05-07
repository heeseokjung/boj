#include <cstdio>
#include <utility>
#include <vector>
using namespace std;

inline double expectation(int s, int a) {
    if(s == 0 && a == 0)
        return 0;
    double _s = (double)s;
    double _a = (double)a;
    return (_s*_s) / (_s*_s + _a*_a);
}

int main() {
    int TC;
    scanf("%d", &TC);
    while(TC--) {
        int N, M;
        scanf("%d %d", &N, &M);
        vector<pair<int, int> > v(N+1, pair<int, int>{0, 0});

        for(int i = 0; i < M; ++i) {
            int a, b, p, q;
            scanf("%d %d %d %d", &a, &b, &p, &q);
            v[a].first += p; v[a].second += q;
            v[b].first += q; v[b].second += p;
        }

        vector<int> list;
        for(int i = 1; i <= N; ++i) {
            double e = expectation(v[i].first, v[i].second);
            list.push_back((int)(e * 1000.0f));
        }

        int mn = 1000, mx = 0;
        for(int i = 0; i < N; ++i) {
            mn = (mn > list[i] ? list[i] : mn);
            mx = (mx < list[i] ? list[i] : mx);
        }

        printf("%d\n", mx);
        printf("%d\n", mn);
    }
    return 0;
}