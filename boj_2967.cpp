#include <iostream>
#include <cstdio>
#include <string>
#include <utility>
#include <algorithm>
using namespace std;

int R, C;
char arr[100][100];
int u[100][100], d[100][100], l[100][100], r[100][100];
int ans[100][100];

int main() {
    cin >> R >> C;
    for(int i = 0; i < R; ++i) {
        string s;
        cin >> s;
        for(int j = 0; j < C; ++j)
            arr[i][j] = s[j];
    }

    for(int i = 0; i < R; ++i) {
        for(int j = 0; j < C; ++j) {
            if(arr[i][j] == 'x') {
                u[i][j] = l[i][j] = 1;
                if(i > 0)
                    u[i][j] += u[i-1][j];
                if(j > 0)
                    l[i][j] += l[i][j-1];
            }
        }
    }

    for(int i = R-1; i >= 0; --i) {
        for(int j = C-1; j >= 0; --j) {
            if(arr[i][j] == 'x') {
                d[i][j] = r[i][j] = 1;
                if(i < R-1)
                    d[i][j] += d[i+1][j];
                if(j < C-1)
                    r[i][j] += r[i][j+1];
            }
        }
    }

    for(int i = 0; i < R; ++i) {
        for(int j = 0; j < C; ++j) {
            if(arr[i][j] != 'x')
                continue;
            int U = u[i][j] - 1, D = d[i][j] - 1;
            int L = l[i][j] - 1, R = r[i][j] - 1;

            int count = (U > 0) + (D > 0) + (L > 0) + (R > 0);
            
            if(count < 2)
                ans[i][j] = -1;
            if(count > 2)
                continue;

            if(L && U)
                ans[i-min(L, U)][j-min(L, U)] = -min(L, U) - 1;
            if(L && D)
                ans[i][j-min(L, D)] = -min(L, D) - 1;
            if(R && U)
                ans[i-min(R, U)][j] = -min(R, U) - 1;
            if(R && D)
                ans[i][j] = -min(R, D) - 1;
        }
    }

    int ii, jj, count = 0;
    for(int i = 0; i < R; ++i) {
        for(int j = 0; j < C; ++j) {
            if(ans[i][j] < 0) {
                printf("%d %d %d\n", i+1, j+1, -ans[i][j]);
                ii = i + 1;
                jj = j + 1;
                count++;
            }
        }
    }
    if(count == 1)
        printf("%d %d 1\n", ii, jj);

    return 0;
}