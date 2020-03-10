#include <iostream>
#include <utility>
#include <string>
using namespace std;

inline int absl(int x) {
    return x < 0 ? -x : x;
}

inline int dist(pair<int, int> p1, pair<int, int> p2) {
    return absl(p1.first - p2.first) + absl(p1.second - p2.second);
}

int main() {
    char arr[4][4];
    for(int i = 0; i < 4; ++i) {
        string s;
        cin >> s;
        for(int j = 0; j < 4; ++j)
            arr[i][j] = s[j];
    }
    pair<int, int> answer[16] = {{0, 0}, {0, 1}, {0, 2}, {0, 3},
                                 {1, 0}, {1, 1}, {1, 2}, {1, 3},
                                 {2, 0}, {2, 1}, {2, 2}, {2, 3},
                                 {3, 0}, {3, 1}, {3, 2}, {3, 3}};
    int sum = 0;
    for(int i = 0; i < 4; ++i) {
        for(int j = 0; j < 4; ++j) {
            if(arr[i][j] >= 65 && arr[i][j] <= 90)
                sum += dist(pair<int, int>(i, j), answer[arr[i][j]-'A']);
        }
    }
    cout << sum << "\n";
    return 0;
}