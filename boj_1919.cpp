#include <iostream>
#include <string>
using namespace std;

string s1, s2;
int c1[26], c2[26];

inline int diff(int x, int y) {
    return (x < y) ? y-x : x-y;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> s1 >> s2;
    int s1_size = (int)s1.size();
    int s2_size = (int)s2.size();
    for(int i = 0; i < s1_size; ++i)
        c1[s1[i] - 'a']++;
    for(int i = 0; i < s2_size; ++i)
        c2[s2[i] - 'a']++;
    int ans = 0;
    for(int i = 0; i < 26; ++i)
        ans += diff(c1[i], c2[i]);
    cout << ans << "\n";
    return 0;
}