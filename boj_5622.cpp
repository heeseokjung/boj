#include <iostream>
#include <string>
using namespace std;

int cost[26] = {3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6,
                7, 7, 7, 8, 8, 8, 8, 9, 9, 9, 10, 10, 10, 10};

int main() {
    string s;
    cin >> s;
    int sum = 0;
    for(int i = 0; i < (int)s.size(); ++i)
        sum += cost[s[i] - 'A'];
    cout << sum << "\n";
}