#include <cstdio>
#include <vector>
using namespace std;

int N, M;
int ans = (int)1e9;
vector<int> f(10, 1);

inline int absl(int x) {
    return x < 0 ? -x : x;
}

int vtoi(vector<int>& v) {
    int ret = 0;
    for(int i = 0; i < (int)v.size(); ++i)
        ret = 10*ret + v[i];
    return ret;
}

void search(int depth, vector<int>& v) {
    if(depth > 6) {
        int len = (int)v.size();
        if(len == 0)
            return;
        int num = vtoi(v);
        if(len + absl(N - num) < ans)
            ans = len + absl(N - num);
        return;
    }
    search(depth + 1, v);
    for(int i = 0; i < 10; ++i) {
        if(f[i]) {
            v.push_back(i);
            search(depth + 1, v);
            v.pop_back();
        }
    }
}

int main() {
    scanf("%d %d", &N, &M);
    for(int i = 0; i < M; ++i) {
        int x;
        scanf("%d", &x);
        f[x] = 0;
    }

    vector<int> v;
    search(0, v);

    if(absl(100 - N) < ans)
        ans = absl(100 - N);

    printf("%d\n", ans);

    return 0;
}