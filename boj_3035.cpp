#include <iostream>
#include <string>
using namespace std;

int main() {
    int r, c, zr, zc;
    cin >> r >> c >> zr >> zc;
    char arr[50][50];
    string s;
    for(int i = 0; i < r; ++i) {
        cin >> s;
        for(int j = 0; j < c; ++j)
            arr[i][j] = s[j];
    }
    for(int i = 0; i < r; ++i) {
        for(int ii = 0; ii < zr; ++ii) {
            for(int j = 0; j < c; ++j) {
                for(int jj = 0; jj < zc; ++jj) {
                    cout << arr[i][j];
                }
            }
            cout << "\n";
        }
    }
    return 0;
}