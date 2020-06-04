#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string x, y;
    getline(cin, x);
    getline(cin, y);

    int x_size = (int)x.size();
    int y_size = (int)y.size();
    vector<int> v;
    for(int i = 0; i <= x_size - y_size; ++i) {
        if(x.substr(i, y_size) == y)
            v.push_back(i);
    }

    int count = 0, tail = -1;
    for(int i = 0; i < (int)v.size(); ++i) {
        if(tail < v[i]) {
            count++;
            tail = v[i] + y_size - 1;
        }
    }

    cout << count << "\n";

    return 0;
}