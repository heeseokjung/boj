#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string s;
    cin >> s;

    vector<int> v;
    int size = (int)s.size();
    for(int i = size-1; i >= 0; i -= 3) {
        int d = (int)(s[i] - '0');
        if(i-1 >= 0)
            d += (int)(s[i-1] - '0')*2;
        if(i-2 >= 0)
            d += (int)(s[i-2] - '0')*4;
        v.push_back(d);
    }

    for(int i = (int)v.size()-1; i >= 0; --i)
        cout << v[i];
    cout << "\n";

    return 0;
}