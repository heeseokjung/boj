#include <cstdio>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int ans = 1000000;
int arr[51][51];
vector<pair<int, int> > house;
vector<pair<int, int> > chicken;

inline int absl(int x) {
    return x < 0 ? -x : x;
}

void comb(int pos, int count, vector<pair<int, int> >& v) {
    if(count == M) {
        int total = 0;
        for(int i = 0; i < (int)house.size(); ++i) {
            int d = 1000000;
            for(int j = 0; j < M; ++j)
                d = min(d, absl(v[j].first - house[i].first) + absl(v[j].second - house[i].second));
            total += d;
        }
        ans = min(ans, total);
    }
    if(pos >= chicken.size())
        return;
    v.push_back(chicken[pos]);
    comb(pos+1, count+1, v);
    v.pop_back();
    comb(pos+1, count, v);
}

int main() {
    scanf("%d %d", &N, &M);
    for(int i = 1; i <= N; ++i) {
        for(int j = 1; j <= N; ++j) {
            scanf("%d", &arr[i][j]);
            switch(arr[i][j]) {
                case 1:
                    house.push_back(pair<int, int>(i, j));
                    break;
                case 2:
                    chicken.push_back(pair<int, int>(i, j));
                    break;
                default:
                    break;
            }
        }
    }
    vector<pair<int, int> > v;
    comb(0, 0, v);
    printf("%d\n", ans);
    return 0;
}