#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

int R, C;
string arr[20];
vector<string> v;
vector<string> ans;

int main() {
    cin >> R >> C;
    for(int i = 0; i < R; ++i)
        cin >> arr[i];

    v.reserve(R + C);
    for(int i = 0; i < R; ++i)
        v.push_back(arr[i]);
    for(int j = 0; j < C; ++j) {
        string s;
        for(int i = 0; i < R; ++i)
            s += arr[i][j];
        v.push_back(s);
        s.clear();
    }

    for(int i = 0; i < R+C; ++i) {
        istringstream iss(v[i]);
        string s;
        while(getline(iss, s, '#')) {
            if(s.size() >= 2) 
                ans.push_back(s);
        }
    }

    sort(ans.begin(), ans.end());
    cout << ans[0] << "\n";

    return 0;
}