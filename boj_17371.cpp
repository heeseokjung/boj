#include <cstdio>
#include <utility>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int N;
    scanf("%d", &N);
    vector<pair<double, double> > v(N);
    for(int i = 0; i < N; ++i)
        scanf("%lf %lf", &v[i].first, &v[i].second);

    double x_sum = 0.0, y_sum = 0.0;
    for(int i = 0; i < N; ++i) {
        x_sum += v[i].first;
        y_sum += v[i].second;
    }
    
    double x = 0.0, y = -1.0;
    double mx = 0.0, mn = 10000000.0;
    for(int i = 0; i < N; ++i) {
        double sum = (x-v[i].first)*(x-v[i].first) + (y-v[i].second)*(y-v[i].second);
        double dist = sqrt(sum);
        if(dist > mx)
            mx = dist;
        if(dist < mn)
            mn = dist;
    }

    double avr = (mx + mn)/2.0;
    double ans = 2.0 * sqrt(2);

    printf("myanswer: %f answer: %f\n", avr, ans);
    
    return 0;
}