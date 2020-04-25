#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    string input;
    cin >> input;

    vector<string> s;
    s.push_back("ABC");
    s.push_back("BABC");
    s.push_back("CCAABB");

    int score[3] = {0, 0, 0};
    for(int i = 0; i < N; ++i) {
        if(input[i] == s[0][i%3])
            score[0]++;
        if(input[i] == s[1][i%4])
            score[1]++;
        if(input[i] == s[2][i%6])
            score[2]++;
    }

    int mx = -1;
    for(int i = 0; i < 3; ++i) {
        if(score[i] > mx)
            mx = score[i];
    }

    cout << mx << "\n";
    if(score[0] == mx)
        cout << "Adrian\n";
    if(score[1] == mx)
        cout << "Bruno\n";
    if(score[2] == mx)
        cout << "Goran\n";

    return 0;
}