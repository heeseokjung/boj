#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    string s1, s2;
    cin >> s1 >> s2;
    int T;
    cin >> T;

    vector<char> v;
    if(T > M) {
        int i, j = M-1;
        for(i = 0; i <= min(T-M, N-1); ++i)
            v.push_back(s1[i]);
        while(i < N || j >= 0) {
            if(j >= 0)
                v.push_back(s2[j]);
            if(i < N)
                v.push_back(s1[i]);
            ++i; --j;
        }

    } else {
        int i = 0, j;
        for(j = M-1; j >= T; --j)
            v.push_back(s2[j]);
        while(i < N || j >= 0) {
            if(i < N)
                v.push_back(s1[i]);
            if(j >= 0)
                v.push_back(s2[j]);
            ++i; --j;
        }
    }
    for(int i = (int)v.size()-1; i >= 0; --i)
        cout << v[i];
    cout << "\n";
    return 0;
}