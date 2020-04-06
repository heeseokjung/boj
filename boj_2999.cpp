#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;

    int size = (int)s.size();
    int r = 1, c;
    for(int i = 1; i*i <= size; ++i) {
        if(size % i == 0)
            r = i;
    }
    c = size / r;

    char arr[100][100];
    for(int i = 0; i < size; ++i)
        arr[i%r][i/r] = s[i];
    
    for(int i = 0; i < r; ++i) {
        for(int j = 0; j < c; ++j) {
            cout << arr[i][j];
        }
    } 
    cout << "\n";

    return 0;
}