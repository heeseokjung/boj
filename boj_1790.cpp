#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

inline int pow(int x) {
    int ret = 1;
    for(int i = 0; i < x; ++i)  
        ret *= 10;
    return ret;
}

int main() {
    int N, K;
    scanf("%d %d", &N, &K);

    int order = 1;
    while(true) {
        int x = 1;
        for(int i = 0; i < order-1; ++i)
            x *= 10;
        if(N/x == 0) {
            order--;
            break;
        } 
        order++;
    }

    long long len = 0;
    for(int i = 1, j = 9; i < order; ++i, j *= 10)
        len += (long long)i * (long long)j;
    len += (long long)(N - pow(order-1) + 1) * (long long)order;
    
    if(len < (long long)K) {
        printf("-1\n");
    } else {
        long long i = 1, j = 9, k = 0;
        while(true) {
            if(k + i*j >= K) {
                break;
            }
            k += i*j;
            i++;
            j *= 10;
        }
        long long num = pow(i-1) + (K - k - 1)/i;
        long long pos = (K - k - 1)%i;

        vector<int> v;
        while(num) {
            v.push_back(num % 10);
            num /= 10;
        }
        reverse(v.begin(), v.end());
        printf("%d\n", v[pos]);
    }

    return 0;
}