#include <cstdio>
#include <utility>
using namespace std;

int main() {
    int C, R, K;
    scanf("%d %d %d", &C, &R, &K);
    if(K > C*R) {
        printf("0\n");
        return 0;
    }
    pair<int, int> p = pair<int, int>(1, 1);
    while(true) {
        if(K - (2*R + 2*C - 4) <= 0)
            break;
        K = K - (2*R + 2*C - 4);
        R -= 2; C -= 2;
        p.first++; p.second++;
    }
    for(int i = 0; i < R-1; ++i, --K) {
        if(K == 1) {
            printf("%d %d\n", p.first, p.second);
            return 0;
        }
        p.second++;
    }
    for(int i = 0; i < C-1; ++i, --K) {
        if(K == 1) {
            printf("%d %d\n", p.first, p.second);
            return 0;
        }
        p.first++;
    }
    for(int i = 0; i < R-1; ++i, --K) {
        if(K == 1) {
            printf("%d %d\n", p.first, p.second);
            return 0;
        }
        p.second--;
    }
    for(int i = 0; i < C-1; ++i, --K) {
        if(K == 1) {
            printf("%d %d\n", p.first, p.second);
            return 0;
        }
        p.first--;
    }
}