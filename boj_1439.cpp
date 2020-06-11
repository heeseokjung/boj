#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;

    int one = 0, zero = 0;
    int size = (int)s.size();
    for(int i = 0; i < size; ) {
        if(s[i] == '1') {
            one++;
            while(i < size && s[i] == '1')
                i++;
        } else {
            zero++;
            while(i < size && s[i] == '0')
                i++;
        }
    }

    cout << min(one, zero) << "\n";

    return 0;
}