#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    string s;
    cin >> s;
    
    int size = (int)s.size();
    vector<string> v;
    for(int i = 0; i < size-2; ++i) {
        for(int j = i+1; j < size-1; ++j) {
            string c1 = s.substr(0, i+1);
            string c2 = s.substr(i+1, j-i);
            string c3 = s.substr(j+1, size-1-j);
            reverse(c1.begin(), c1.end());
            reverse(c2.begin(), c2.end());
            reverse(c3.begin(), c3.end());
            v.push_back(c1 + c2 + c3);
        }
    }

    sort(v.begin(), v.end());

    cout << v[0] << "\n";

    return 0;
}