#include <iostream>
#include <string>
#include <utility>
#include <vector>
using namespace std;

inline int ccw(pair<int, int>& p1, pair<int, int>& p2, pair<int, int>& p3) {
    return (p2.first - p1.first)*(p3.second - p1.second) -
           (p2.second - p1.second)*(p3.first - p1.first);
}

int main(){
    int N;
    cin >> N;
    vector<pair<int, int> > v;
    for(int i = 0; i < N; ++i) {
        string s;
        cin >> s;
        for(int j = 0; j < N; ++j) {
            if(s[j] != '.')
                v.push_back(pair<int, int>(i, j));
        }
    }
    int size = (int)v.size(), count = 0;
    for(int i = 0; i < size-2; ++i) {
        for(int j = i+1; j < size-1; ++j) {
            for(int k = j+1; k < size; ++k) {
                if(ccw(v[i], v[j], v[k]) == 0)
                    count++;
            }
        }
    }
    cout << count << "\n";
    return 0;
}