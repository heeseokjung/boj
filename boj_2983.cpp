#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

int N, K;
string cmd;
vector<pair<int, int> > v;

typedef struct Point {
    int key;
    int x;
    int y;
    int idx;
}Point;

vector<struct Point> sum;
vector<struct Point> diff;
int sum_idx[100001];
int diff_idx[100001];
bool visit[100001];

inline int absl(int x) {
    return x < 0 ? -x : x;
}

inline bool comp(Point& p1, Point& p2) {
    if(p1.key < p2.key) {
        return true;
    } else if(p1.key > p2.key) {
        return false;
    } else {
        return p1.x < p2.x;
    }
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

    sum.reserve(N);
    diff.reserve(N);
    for(int i = 0; i < N; ++i) {
        sum.push_back(Point{v[i].first + v[i].second, v[i].first, v[i].second, i});
        diff.push_back(Point{v[i].first - v[i].second, v[i].first, v[i].second, i});
    }

    sort(sum.begin(), sum.end(), comp);
    sort(diff.begin(), diff.end(), comp);

    for(int i = 0; i < N; ++i) {
        sum_idx[sum[i].idx] = i;
        diff_idx[diff[i].idx] = i;
    }

    int pos = 0;
    for(int i = 0; i < K; ++i) {
        visit[pos] = true;
        switch(cmd[i]) {
            case 'A': {
                int p = diff_idx[pos];
                int q = p + 1;
                while(q < N && visit[diff[q].idx])
                    q++;
                if(q < N && diff[p].key == diff[q].key && 
                   absl(diff[p].x - diff[q].x) == absl(diff[p].y - diff[q].y)) {
                    //change = true;
                    pos = diff[q].idx;
                }
                break;
            }
            case 'B': {
                int p = sum_idx[pos];
                int q = p + 1;
                while(q < N && visit[sum[q].idx])
                    q++;
                if(q < N && sum[p].key == sum[q].key &&
                   absl(sum[p].x - sum[q].x) == absl(sum[p].y - sum[q].y)) {
                    //change = true;
                    pos = sum[q].idx;
                }
                break;
            }
            case 'C': {
                int p = sum_idx[pos];
                int q = p - 1;
                while(q >= 0 && visit[sum[q].idx])
                    q--;
                if(q >= 0 && sum[p].key == sum[q].key && 
                   absl(sum[p].x - sum[q].x) == absl(sum[p].y - sum[q].y)) {
                    //change = true;
                    pos = sum[q].idx;
                }
                break;
            }
            case 'D': {
                int p = diff_idx[pos];
                int q = p - 1;
                while(q >= 0 && visit[diff[q].idx])
                    q--;
                if(q >= 0 && diff[p].key == diff[q].key &&
                   absl(diff[p].x - diff[q].x) == absl(diff[p].y - diff[q].y)) {
                    //change = true;
                    pos = diff[q].idx;
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