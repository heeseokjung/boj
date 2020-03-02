#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    string s;
    cin >> s;
    stack<int> st;
    int size = (int)s.size();
    int ans = 0;
    for(int i = 0; i < size; ++i) {
        if(s[i] == '(') {
            st.push(i);
        } else if(s[i] == ')') {
            int j = st.top(); st.pop();
            if(i - j == 1)
                ans += (int)st.size();
            else
                ans++;
        }
    }
    cout << ans << "\n";
    return 0;
}