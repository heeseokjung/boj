#include <cstdio>
#include <utility>
#include <vector>
using namespace std;

int main() {
    int N, K;
    scanf("%d %d",&N, &K);
    getchar();

    vector<pair<char, int> > v(K);
    for(int i = 0; i < K; ++i) {
        scanf("%c %d", &v[i].first, &v[i].second);
        getchar();
    }

    int P;
    scanf("%d", &P);
    vector<int> subset(P);
    for(int i = 0; i < P; ++i)
        scanf("%d", &subset[i]);

    return 0;
}