#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int TC;
    cin >> TC;
    while(TC--) {
        string cmd;
        cin >> cmd;

        int dr[4] = {1, 0, -1, 0};
        int dc[4] = {0, 1, 0, -1};
        int min_r = 0, max_r = 0;
        int min_c = 0, max_c = 0;

        int r = 0, c = 0;
        for(int i = 0, j = 0; i < (int)cmd.size(); ++i) {
            switch(cmd[i]) {
                case 'F':
                    r += dr[j];
                    c += dc[j];
                    break;
                case 'B':
                    r -= dr[j];
                    c -= dc[j];
                    break;
                case 'L':
                    j = (j+3)%4;
                    break;
                case 'R':
                    j = (j+1)%4;
                    break;
                default:
                    break;
            }

            min_r = (min_r > r ? r : min_r);
            max_r = (max_r < r ? r : max_r);
            min_c = (min_c > c ? c : min_c);
            max_c = (max_c < c ? c : max_c);
        }

        cout << (max_r - min_r)*(max_c - min_c) << "\n";
    }
    return 0;
}