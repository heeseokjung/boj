#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int N, size;
vector<int> prime;

inline bool is_prime(int x) {
    for(int i = 2; i*i <= x; ++i) {
        if(x % i == 0)
            return false;
    }
    return true;
}

vector<int> check(int x) {
    int p = 0;
    while(p < size && prime[p] < x)
        p++;
    if(p == size)
        p--;
    vector<int> v;
    for(int i = 0; i <= p; ++i) {
        for(int j = i; j <= p; ++j) {
            for(int k = j; k <= p; ++k) {
                if(prime[i] + prime[j] + prime[k] == x) {
                    v.push_back(prime[i]);
                    v.push_back(prime[j]);
                    v.push_back(prime[k]);
                    return v;
                }
            }
        }
    }
    return v;
}

int main() {
    for(int i = 2; i <= 1000; ++i) {
        if(is_prime(i))
            prime.push_back(i);
    }
    size = (int)prime.size();
    int TC;
    scanf("%d", &TC);
    while(TC--) {
        scanf("%d", &N);
        vector<int> ans = check(N);
        if(!ans.empty()) {
            sort(ans.begin(), ans.end());
            printf("%d %d %d\n", ans[0], ans[1], ans[2]);
        }
        else {
            printf("0\n");
        }
    }
    return 0;
}