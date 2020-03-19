#include <iostream>
#include <string>
using namespace std;

inline void swap(int& x, int& y) {
    int tmp = x;
    x = y;
    y = tmp;
}

int main() {
    string s;
    cin >> s;
    int cup[3] = {1, 0, 0};
    for(int i = 0; i < (int)s.size(); ++i) {
        switch(s[i]) {
            case 'A': 
                swap(cup[0], cup[1]);
                break;
            case 'B':
                swap(cup[1], cup[2]);
                break;
            case 'C':
                swap(cup[0], cup[2]);
                break;
            default:
                break;
        }
    }
    for(int i = 0; i < 3; ++i) {
        if(cup[i]) {
            cout << i+1 << "\n";
            break;
        }
    }
    return 0;
}