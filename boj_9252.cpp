#include <stdio.h>
#include <iostream>
#include <string>
#include <stack>

#define UP 0
#define LEFT 1
#define DIAGONAL 2

using namespace std;

string str1, str2;
int dp[1001][1001] = {0, };
int lcs[1001][1001];

void run();
void print_lcs(int m, int n);

int main()
{
    cin >> str1 >> str2;

    run();
    
    return 0;
}

void run()
{
    int m = str1.length();
    int n = str2.length();

    for(int i = 1; i <= m; ++i) {
        for(int j = 1; j <= n; ++j) {
            if(str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                lcs[i][j] = DIAGONAL;
            }
            else {
                if(dp[i - 1][j] < dp[i][j - 1]) {
                    dp[i][j] = dp[i][j - 1];
                    lcs[i][j] = LEFT;
                }
                else {
                    dp[i][j] = dp[i - 1][j];
                    lcs[i][j] = UP;
                }
            }
        }
    }

    printf("%d\n", dp[m][n]);

    print_lcs(m, n);
}

void print_lcs(int m, int n)
{
    int i = m;
    int j = n;
    stack<char> s;

    while(i > 0 && j > 0) {
        switch(lcs[i][j]) {
            case UP:
                i = i - 1;
                break;
            case LEFT:
                j = j - 1;
                break;
            case DIAGONAL:
                s.push(str1[i - 1]);
                i = i - 1;
                j = j - 1;
                break;
            default:
                break;
        }
    }

    while(!s.empty()) {
        printf("%c", s.top());
        s.pop();
    }
    printf("\n");
}