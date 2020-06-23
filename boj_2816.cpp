#include <iostream>
#include <string>
#include <vector>
using namespace std;

inline void swap(string& s1, string& s2) {
    string tmp = s1;
    s1 = s2;
    s2 = tmp;
}

int main() {
    int N;
    cin >> N;
    vector<string> v(N);
    for(int i = 0; i < N; ++i)
        cin >> v[i];

    int pos = 0;
    vector<int> cmd;
    string target[2] = {"KBS1", "KBS2"};
    int target_pos[2] = {0, 1};
    for(int i = 0; i < 2; ++i) {
        while(v[pos] != target[i]) {
            pos++;
            cmd.push_back(1);
        }
        for(int j = pos; j > target_pos[i]; --j) {
            swap(v[j-1], v[j]);
            pos = j-1;
            cmd.push_back(4);
        }
    }

    for(int i = 0; i < (int)cmd.size(); ++i)
        cout << cmd[i];
    cout << "\n";

    return 0;
}