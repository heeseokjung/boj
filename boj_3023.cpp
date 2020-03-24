#include <iostream>
#include <string>
using namespace std;

int R, C;
char arr[50][50];
char ans[100][100];

int main() {
    cin >> R >> C;
    string s;
    for(int i = 0; i < R; ++i) {
        cin >> s;
        for(int j = 0; j < C; ++j)
            arr[i][j] = s[j];
    }
    int ERR_R, ERR_C;
    cin >> ERR_R >> ERR_C;
    for(int i = 0; i < R; ++i) {
        for(int j = 0; j < C; ++j) {
            ans[i][j] = arr[i][j];
        }
    }
    for(int i = 0; i < R; ++i) {
        for(int j = 0; j < C; ++j) {
            ans[i][2*C-1-j] = ans[i][j];
        }
    }
    for(int j = 0; j < 2*C; ++j) {
        for(int i = 0; i < R; ++i) {
            ans[2*R-1-i][j] = ans[i][j];
        }
    }
    ans[ERR_R-1][ERR_C-1] = (ans[ERR_R-1][ERR_C-1] == '#' ? '.' : '#');
    for(int i = 0; i < 2*R; ++i) {
        for(int j = 0; j < 2*C; ++j) {
            cout << ans[i][j];
        }
        cout << "\n";
    }
    return 0;
}