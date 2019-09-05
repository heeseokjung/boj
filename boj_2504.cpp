#include <stdio.h>
#include <stack>
using namespace std;

char arr[31];
int ans = 0;
bool ERR = false;

void input()
{
    fgets(arr, sizeof(arr), stdin);
}

void run()
{
    int x = 1;
    stack<int> s;
    for(int i = 0; arr[i] != '\0'; ++i) {
        switch(arr[i]) {
            case '(':
                s.push(arr[i]);
                x = x * 2;
                break;
            case '[':
                s.push(arr[i]);
                x = x * 3;
                break;
            case ')':
                if(s.empty() || s.top() != '(') {
                    ERR = true;
                    break;
                }
                if(arr[i-1] == '(')
                    ans += x;
                s.pop();
                x = x / 2;
                break;
            case ']':
                if(s.empty() || s.top() != '[') {
                    ERR = true;
                    break;
                }
                if(arr[i-1] == '[')
                    ans += x;
                s.pop();
                x = x / 3;
                break;
        }
    }
    if(!s.empty())
        ERR = true;

    printf("%d\n", ERR ? 0 : ans);
}

int main()
{
    input();
    run();
    return 0;
}