#include <iostream>
#include <algorithm>
using namespace std;

int R, C;
char arr[410][410];
int rsum[410][410];

inline bool is_blocked(int row, int s, int e) {
    if(rsum[row][e] - (s == 0 ? 0 : rsum[row][s-1]))
        return true;
    else
        return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> R >> C;
    for(int i = 0; i < R; ++i) {
        string s;
        cin >> s;
        for(int j = 0; j < C; ++j)
            arr[i][j] = s[j];
    }
    for(int i = 0; i < R; ++i) {
        for(int j = 0; j < C; ++j) {
            if(j == 0)
                rsum[i][j] = (arr[i][j] == 'X' ? 1 : 0);
            else
                rsum[i][j] = rsum[i][j-1] + (arr[i][j] == 'X' ? 1 : 0);
        }
    }
    int ans = 1;
    for(int i = 0; i < C; ++i) {
        for(int j = i; j < C; ++j) {
            int width = j - i + 1;
            int height = 0, max_height = 0;
            for(int k = 0; k < R; ++k) {
                if(!is_blocked(k, i, j)) {
                    height = (height == 0 ? 1 : height + 1);
                    max_height = max(max_height, height);
                } else {
                    height = 0;
                }
            }
            if(max_height > 0)
                ans = max(ans, 2*width + 2*max_height);
        }
    }
    cout << ans-1 << "\n";
    return 0;
}