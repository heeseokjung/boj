#include <iostream>
#include <string>
#define MOD 1000000
using namespace std;

int main() {
    string code;
    cin >> code;
    int size = (int)code.size();
    int dp[5000];
    for(int i = 0; i < size; ++i)
        dp[i] = 0;
    bool check = false;
    for(int i = 0; i < size; ++i) {
        int x = code[i] - '0';
        if(i == 0){
            dp[i] = (x != 0) ? 1 : 0;
        } else if(i == 1) {
            int prev = code[i-1] - '0';
            if(x != 0)
                dp[i] = dp[i-1];
            if(prev*10 + x <= 26 && prev != 0)
                dp[i] += 1;
        } else {
            int prev = code[i-1] - '0';
            if(x == 0) {
                if(prev*10 + x <= 26 && prev != 0)
                    dp[i] = dp[i-2];
            }
            else {
                dp[i] = dp[i-1];
                int prev = code[i-1] - '0';
                if(prev*10 + x <= 26 && prev != 0)
                    dp[i] = (dp[i] + dp[i-2]) % MOD;
            }
        }
    }
    cout << dp[size-1] << "\n";
    return 0;
}