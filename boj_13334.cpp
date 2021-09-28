#include <cstdio>
#include <utility>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, d;
int mx = 0;
vector<pair<int, int> > v;
priority_queue<int, vector<int>, greater<int> > pq;

inline bool cmp(pair<int, int>& p1, pair<int, int>& p2) {
    if(p1.second != p2.second)
        return p1.second < p2.second;
    else
        return p1.first < p2.first;
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        int h, o;
        scanf("%d %d", &h, &o);
        if(h < o)
            v.push_back(pair<int, int>(h, o));
        else
            v.push_back(pair<int, int>(o, h));
    }
    scanf("%d", &d);

    sort(v.begin(), v.end(), cmp);

    for(int i = 0; i < n; ++i) {
        int l = v[i].first;
        int r = v[i].second;

        if(r - l > d)
            continue;

        pq.push(l); 

        while(!pq.empty()) {
            int ll = pq.top();
            if(r - ll <= d)
                break;
            else
                pq.pop();
        }

        mx = max(mx, (int)pq.size());
    }

    printf("%d\n", mx);

    return 0;
}