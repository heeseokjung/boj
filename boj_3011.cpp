#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

inline int absl(int x) {
    return x < 0 ? -x : x;
}

int main() {
    int N;
    scanf("%d", &N);
    vector<int> v(N);
    for(int i = 0; i < N; ++i)
        scanf("%d", &v[i]);
    int A, B;
    scanf("%d %d", &A, &B);

    vector<int> candidate;
    candidate.push_back(A % 2 ? A : A+1);
    candidate.push_back(B % 2 ? B : B-1);

    sort(v.begin(), v.end());
    for(int i = 0; i < N-1; ++i) {
        int mid = (v[i+1] + v[i])/2;
        if(mid % 2 && A <= mid && mid <= B) {
            candidate.push_back(mid);
        } else {
            if(A <= mid+1 && mid+1 <= B)
                candidate.push_back(mid+1);
            else if(A <= mid-1 && mid-1 <= B)
                candidate.push_back(mid-1);
        }
    }

    int max_diff = -1, ans;
    for(int i = 0; i < (int)candidate.size(); ++i) {
        int mn = (int)2e9;
        for(int j = 0; j < N; ++j)
            mn = min(mn, absl(candidate[i] - v[j]));
        if(max_diff < mn) {
            ans = candidate[i];
            max_diff = mn;
        }
    }
    printf("%d\n", ans);

    return 0;
}