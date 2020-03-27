#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

int N;
long long cache[200][200];
bool carry[200][200];
string s;
#define mod 100000

inline bool is_pair(char x, char y) {
    if(x == '?' && (y == ')' || y == '}' || y == ']' || y == '?'))
        return true;
    if(x == '(')
        return (y == ')' || y == '?');
    if(x == '{')
        return (y == '}' || y == '?');
    if(x == '[')
        return (y == ']' || y == '?');
    return false;
}

long long dp(int x, int y, int d) {
    if(x > y)
        return 1LL;
    if(cache[x][y] != -1)
        return cache[x][y];
    long long count = 0;
    for(int i = x+1; i <= y; i += 2) {
        if(is_pair(s[x], s[i])) {
            //printf("x: %d y: %d d: %d i: %d\n", x, y, d, i);
            count += (dp(x+1, i-1, d+1) * dp(i+1, y, d+1));
            if(count >= mod || carry[x+1][i-1] || carry[i+1][y]) {
                count %= mod;
                carry[x][y] = true;
            }
        }
    }
    return cache[x][y] = count;
}

int main() {
    cin >> N >> s;
    for(int i = 0; i < N; ++i)
        for(int j = 0; j < N; ++j)
            cache[i][j] = -1;
    printf((carry[0][N-1] ? "%05lld\n" : "%lld\n"), dp(0, N-1, 0));
    /*
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            printf("i: %d j: %d cache: %lld\n", i, j, cache[i][j]);
        }
    }
    */
    return 0;
}