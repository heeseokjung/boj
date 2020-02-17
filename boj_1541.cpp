#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
    string exp;
    cin >> exp;
    int size = (int)exp.size();
    stack<int> s;
    int ans = 0, x = 0;
    bool open = false;
    for(int i = 0; i < size; ++i) {
        if(exp[i] == '-') {
            if(open) {
                s.push(x);
                while(!s.empty()) {
                    ans -= s.top();
                    s.pop();
                }
                x = 0;
            } else {
                ans += x;
                x = 0;
                open = true;
            }
        } else if(exp[i] == '+') {
            if(open) {
                s.push(x);
                x = 0;
            } else {
                ans += x;
                x = 0;
            }
        } else {
            x = x*10 + (exp[i] - '0');
        }
        //cout << "i: " << i << "x: " << x << endl;
    }
    if(open)
        s.push(x);
    else
        ans += x;
    while(!s.empty()) {
        //cout << "s.top(): " << s.top() << endl;
        ans -= s.top();
        s.pop();
    }
    cout << ans << "\n";
    return 0;
}