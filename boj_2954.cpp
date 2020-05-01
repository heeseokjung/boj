#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    getline(cin, s);

    int size = (int)s.size();
    string ans;
    int i, j;
    for(i = 0, j = 0; i < size && j < size; ) {
        if(s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u') {
            ans += s.substr(i, j-i+1);
            i = j+3;
            j = i;
        } else {
            ++j;
        }
    }

    if(--j >= i)
        ans += s.substr(i, j-i+1);

    cout << ans << "\n";

    return 0;
}