#include <iostream>
#include <string>
using namespace std;

string s;
string str[2];
int count = 0;
int S, T;
int dp[2][100][20];

int dfs(int i, int j, int k) {
    if(k < 0) {
        return 1;
    }
    if(j < 0) {
        return 0;
    }
    if(dp[i][j][k] != -1)
        return dp[i][j][k];
    int r = dfs(i, j-1, k);
    if(str[i][j] == s[k])
        r += dfs(1-i, j-1, k-1);
    return dp[i][j][k] = r;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> s >> str[0] >> str[1];
    S = (int)s.size(); T = (int)str[0].size();
    
    for(int i = 0; i < 2; ++i) {
        for(int j = 0; j < T; ++j) {
            for(int k = 0; k < S; ++k)
                dp[i][j][k] = -1;
        }
    }
    cout << dfs(0, T-1, S-1) + dfs(1, T-1, S-1) << "\n";
}