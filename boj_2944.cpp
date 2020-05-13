#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, H;
    cin >> N >> H;
    int adj[20][20];
    for(int i = 0; i < N; ++i) {
        string s;
        cin >> s;
        for(int j = 0; j < (int)s.size(); ++j)
            adj[i][j] = s[j] - '0';
    }

    set<int> s;
    vector<int> v1, v2;
    for(int i = 0; i < N; ++i) {
        if(s.find(i) == s.end()) {
            v1.push_back(i);
            for(int j = 0; j < N; ++j) {
                if(adj[i][j] && s.find(j) == s.end()) {
                    v2.push_back(j);
                    s.insert(j);
                }
            }
        }
    }

    return 0;
}