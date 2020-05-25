#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;

    int num[10];
    for(int i = 0; i < 10; ++i)
        num[i] = 0;
    for(int i = 0; i < (int)s.size(); ++i)
        num[s[i]-'0']++;

    if(num[0] == 0) {
        cout << "-1\n";
    } else {
        int sum = 0;
        vector<int> v;
        for(int i = 9; i > 0; --i) {
            for(int j = 0; j < num[i]; ++j)
                sum += i;
        }

        if(sum % 3) {
            cout << "-1\n";
        } else {
            for(int i = 9; i >= 0; --i) {
                for(int j = 0; j < num[i]; ++j)
                    cout << i;
            }
            cout << "\n";
        }
    }

    return 0;
}