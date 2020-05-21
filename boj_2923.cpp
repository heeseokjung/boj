#include <cstdio>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<pair<int, int> > v;
vector<int> a(101, 0), b(101, 0);

int get_max() {
    vector<int> copy_a = a;
    vector<int> copy_b = b;
    int ret = 0;
    int i = 1, j = 100;
    while(i <= 100 && j >= 1) {
        if(copy_a[i] < copy_b[j]) {
            if(copy_a[i]) {
                ret = max(ret, i+j);
                copy_b[j] -= copy_a[i];
            }
            ++i;
        } else {
            if(copy_b[j]) {
                ret = max(ret, i+j);
                copy_a[i] -= copy_b[j];
            }
            --j;
        }
    }
    return ret;
}

int main() {
    scanf("%d", &N);
    v = vector<pair<int, int> >(N);
    for(int i = 0; i < N; ++i)
        scanf("%d %d", &v[i].first, &v[i].second);

    for(int i = 0; i < N; ++i) {
        a[v[i].first]++;
        b[v[i].second]++;
        printf("%d\n", get_max());
    }

    return 0;
}