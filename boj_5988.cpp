#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    string s;
    for(int i = 0; i < N; ++i) {
        cin >> s;
        char c = s[(int)s.size() - 1];
        if((c - '0') % 2)
            cout << "odd" << "\n";
        else
            cout << "even" << "\n";
    }
    return 0;
}