#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;

    int size = (int)s.size();
    string a = "AAAA", b = "BB";
    string ans = "";
    for(int i = 0; i < size; ) {
        if(s[i] == 'X') {
            int count = 0;
            while(s[i] == 'X') {
                count++;
                i++;
            }
            while(count) {
                if(count >= 4) {
                    ans += a;
                    count -= 4;
                } else if(count >= 2) {
                    ans += b;
                    count -= 2;
                } else {
                    cout << "-1\n";
                    return 0;
                }
            }
        } else {
            ans += s[i];
            i++;
        }
    }

    cout << ans << "\n";

    return 0;
}