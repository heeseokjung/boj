#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string s;
    cin >> s;
    if(next_permutation(s.begin(), s.end()))
        cout << s << "\n";
    else
        cout << "0\n";
    return 0;
}