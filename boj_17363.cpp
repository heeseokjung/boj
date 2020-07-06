#include <iostream>
#include <string>
using namespace std;

inline char convert(char c) {
    if(c == '.') return '.';
    else if(c == 'O') return 'O';
    else if(c == '-') return '|';
    else if(c == '|') return '-';
    else if(c == '/') return 92;
    else if(c == 92) return '/';
    else if(c == '^') return '<';
    else if(c == '<') return 'v';
    else if(c == 'v') return '>';
    else if(c == '>') return '^';
}

int main() {
    int n, m;
    cin >> n >> m;
    string arr[100];
    for(int i = 0; i < n; ++i)
        cin >> arr[i];

    for(int j = m-1; j >= 0; --j) {
        for(int i = 0; i < n; ++i) {
            cout << convert(arr[i][j]);
        }
        cout << "\n";
    }

    return 0;
}