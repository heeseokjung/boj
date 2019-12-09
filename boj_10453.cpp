#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int TC;
    string s1, s2;
    vector<int> v1, v2;
    ios::sync_with_stdio(false);
    cin >> TC;
    while(TC--) {
        cin >> s1 >> s2;
        if(s1.size() != s2.size()) {
            cout << "-1" << "\n";
        }
        else {
            int size = (int)s1.size();
            for(int i = 0; i < size; ++i) {
                if(s1[i] == 'a')
                    v1.push_back(i);
                if(s2[i] == 'a')
                    v2.push_back(i);
            }
            int count = 0;
            for(int i = 0; i < (int)v1.size(); ++i) 
                count += (v1[i] < v2[i]) ? v2[i] - v1[i] : v1[i] - v2[i];
            cout << count << "\n";
            v1.clear();
            v2.clear();
        }
    }
    return 0;
}