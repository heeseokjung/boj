#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

int N;
long long cache[200][200];
bool carry[200][200];
string s;
#define mod 100000

inline long long num_pair(char x, char y) {
    if(x == '?') {
        if(y == ')' || y == '}' || y == ']')
            return 1LL;
        if(y == '?')
            return 3LL;
    }
    if(x == '(' && (y == ')' || y == '?')) {
        return 1LL;
    }
    if(x == '{' && (y == '}' || y == '?')) {
        return 1LL;
    }
    if(x == '[' && (y == ']' || y == '?')) {
        return 1LL;
    }
    return 0;
}

long long dp(int x, int y) {
    if(x > y)
        return 1LL;
    if(cache[x][y] != -1)
        return cache[x][y];
    long long count = 0;
    for(int i = x+1; i <= y; i += 2) {
        long long num = num_pair(s[x], s[i]);
        if(num) {
            count += (num * dp(x+1, i-1) * dp(i+1, y));
            if(count >= mod) 
                count = mod + count % mod;
        }
    }
    return cache[x][y] = count;
}

int main() {
    cin >> N >> s;
    for(int i = 0; i < N; ++i)
        for(int j = 0; j < N; ++j)
            cache[i][j] = -1;
    long long ans = dp(0, N-1);
    if(ans >= mod)
        printf("%05lld\n", ans % mod);
    else
        printf("%lld\n", ans);
    return 0;
}