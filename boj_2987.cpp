#include <cstdio>
#include <utility>
#include <vector>
using namespace std;

inline int absl(int x) {
    return x < 0 ? -x : x;
}

inline int ccw(pair<int, int>& p1, pair<int, int>& p2, pair<int, int>& p3) {
    return (p2.first - p1.first)*(p3.second - p1.second) -
           (p2.second - p1.second)*(p3.first - p1.first);
}

int main() {
    pair<int, int> p[3];
    for(int i = 0; i < 3; ++i)
        scanf("%d %d", &p[i].first, &p[i].second);

    int N;
    scanf("%d", &N);
    vector<pair<int, int> > v(N);
    for(int i = 0; i < N; ++i)
        scanf("%d %d", &v[i].first, &v[i].second);

    double area = (double)absl(p[0].first*(p[1].second - p[2].second) +
                               p[1].first*(p[2].second - p[0].second) +
                               p[2].first*(p[0].second - p[1].second)) / 2.0f;

    int count = 0;
    for(int i = 0; i < N; ++i) {
        int x = ccw(p[0], p[1], v[i]);
        int y = ccw(p[1], p[2], v[i]);
        int z = ccw(p[2], p[0], v[i]);
        if(ccw(p[0], p[1], p[2]) < 0 && x <= 0 && y <= 0 && z <= 0)
            count++;
        else if(ccw(p[0], p[1], p[2]) > 0 && x >= 0 && y >= 0 && z >= 0)
            count++;
    }
    printf("%.1f\n%d\n", area, count);

    return 0;
}