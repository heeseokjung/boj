#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    cin >> N >> K;
    string number;
    cin >> number;

    vector<int> v;
    for(int i = 0; i < N; ++i) {
        while(K && !v.empty() && v.back() < number[i]-'0') {
            v.pop_back();
            K--;
        }
        v.push_back(number[i]-'0');
    }

    for(int i = 0; i < (int)v.size()-K; ++i)
        cout << v[i];
    cout << "\n";

    return 0;
}