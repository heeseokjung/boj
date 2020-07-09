#include <cstdio>
#include <utility>
#include <vector>
#include <cmath>
using namespace std;

inline double get_dist(pair<double, double>& p1, pair<double, double>& p2) {
    return sqrt((p1.first-p2.first)*(p1.first-p2.first) + (p1.second-p2.second)*(p1.second-p2.second));
}

int main() {
    int N;
    scanf("%d", &N);
    vector<pair<double, double> > v(N);
    for(int i = 0; i < N; ++i)
        scanf("%lf %lf", &v[i].first, &v[i].second);

    int mn_idx;
    double mn = 100000.0;
    for(int i = 0; i < N; ++i) {
        double mx = 0.0;
        for(int j = 0; j < N; ++j) {
            if(i == j)
                continue;
            double dist = get_dist(v[i], v[j]);
            if(mx < dist)
                mx = dist;
        }
        if(mx < mn) {
            mn = mx;
            mn_idx = i;
        }
    }

    printf("%f %f\n", v[mn_idx].first, v[mn_idx].second);
    
    return 0;
}