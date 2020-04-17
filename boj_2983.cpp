#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <tuple>
#include <set>
using namespace std;

int N, K;
string cmd;
vector<pair<int, int> > v;
set<tuple<int, int, int> > sum;
set<tuple<int, int, int> > diff;

inline int absl(int x) {
    return x < 0 ? -x : x;
}

inline bool same_line(pair<int, int>& p1, pair<int, int>& p2) {
    return absl(p1.first - p2.first) == absl(p1.second - p2.second);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> K;
    cin >> cmd;
    v.reserve(N);
    for(int i = 0; i < N; ++i) {
        int x, y;
        cin >> x >> y;
        v.push_back(pair<int, int>(x, y));
    }

    for(int i = 0; i < N; ++i) {
        sum.insert(make_tuple(v[i].first + v[i].second, v[i].first, i));
        diff.insert(make_tuple(v[i].first - v[i].second, v[i].first, i));
    }

    int pos = 0;
    for(int i = 0; i < K; ++i) {
        switch(cmd[i]) {
            case 'A': {
                auto it = diff.find(make_tuple(v[pos].first - v[pos].second, v[pos].first, pos));
                if(++it == diff.end())
                    break;
                int key, x, idx;
                tie(key, x, idx) = *it;
                if(v[pos].first - v[pos].second == key) {
                    sum.erase(make_tuple(v[pos].first + v[pos].second, v[pos].first, pos));
                    diff.erase(prev(it));
                    pos = idx;
                }
                break;
            }
            case 'B': {
                auto it = sum.find(make_tuple(v[pos].first + v[pos].second, v[pos].first, pos));
                if(++it == sum.end())
                    break;
                int key, x, idx;
                tie(key, x, idx) = *it;
                if(v[pos].first + v[pos].second == key) {
                    sum.erase(prev(it));
                    diff.erase(make_tuple(v[pos].first - v[pos].second, v[pos].first, pos));
                    pos = idx;
                }
                break;
            }
            case 'C': {
                auto it = sum.find(make_tuple(v[pos].first + v[pos].second, v[pos].first, pos));
                if(--it == prev(sum.begin()))
                    break;
                int key, x, idx;
                tie(key, x, idx) = *it;
                if(v[pos].first + v[pos].second == key) {
                    sum.erase(next(it));
                    diff.erase(make_tuple(v[pos].first - v[pos].second, v[pos].first, pos));
                    pos = idx;
                }
                break;
            }
            case 'D': {
                auto it = diff.find(make_tuple(v[pos].first - v[pos].second, v[pos].first, pos));
                if(--it == prev(diff.begin()))
                    break;
                int key, x, idx;
                tie(key, x, idx) = *it;
                if(v[pos].first - v[pos].second == key) {
                    sum.erase(make_tuple(v[pos].first + v[pos].second, v[pos].first, pos));
                    diff.erase(next(it));
                    pos = idx;
                }
                break;
            }
            default: {
                break;
            }
        }
    }

    cout << v[pos].first << " " << v[pos].second << "\n";

    return 0;
}