#include <cstdio>
#include <utility>
#include <vector>
using namespace std;

int N;
bool is_prime[10001];
vector<int> prime;

inline int absl(int x) {
    return x < 0 ? -x : x;
}

int main() {
    int TC;
    scanf("%d", &TC);
    for(int i = 2; i <= 10000; ++i)
        is_prime[i] = true;
    for(int i = 2; i <= 10000; ++i) {
        for(int j = 2; i*j <= 10000; ++j)
            is_prime[i*j] = false;
    }
    for(int i = 2; i <= 10000; ++i) {
        if(is_prime[i])
            prime.push_back(i);
    }
    while(TC--) {
        scanf("%d", &N);
        int size = (int)prime.size();
        int len = 1000000;
        pair<int, int> p;
        for(int i = 0; i < size && prime[i] <= N/2; ++i) {
            if(is_prime[N-prime[i]] && absl(N-prime[i]-prime[i]) < len) {
                len = absl(N-prime[i]-prime[i]);
                p.first = (prime[i] < N-prime[i] ? prime[i] : N-prime[i]);
                p.second = (prime[i] < N-prime[i] ? N-prime[i] : prime[i]); 
            }
        }
        printf("%d %d\n", p.first, p.second);
    }
    return 0;
}