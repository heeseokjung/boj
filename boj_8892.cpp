#include <iostream>
#include <string>
#include <vector>
using namespace std;

int TC, K;
vector<string> v;
string s;

void input()
{
    cin >> K;
    for(int i = 0; i < K; ++i)
        cin >> v[i];
}

bool is_palindrome(string& s)
{
    int end = (int)s.size() - 1;
    for(int i = 0; i <= end / 2; ++i) {
        if(s[i] != s[end - i])
            return false;
    }
    return true;
}

void run()
{
    input();
    for(int i = 0; i < K; ++i) {
        for(int j = 0; j < K; ++j) {
            if(i == j)
                continue;
            s.reserve(v[i].size() + v[j].size());
            s = v[i] + v[j];
            if(is_palindrome(s)) {
                cout << s << "\n";
                return;
            }
        }
    }
    cout << "0\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    v = vector<string>(100);
    cin >> TC;
    while(TC--)
        run();
    return 0;
}