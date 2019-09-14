#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

void str_head(string& s, int x)
{
    if(x / 10)
        s += '0' + x / 10;
    s += '0' + x % 10;
}

void str_tail(string& s, int x)
{
    s += (x / 10) ? '0' + x / 10 : '0';
    s += '0' + x % 10;
}

void run()
{
    int TC, H, W, N;
    string s;
    scanf("%d", &TC);
    while(TC--) {
        scanf("%d %d %d", &H, &W, &N);
        s.clear();
        str_head(s, N % H ? N % H : H);
        str_tail(s, N / H + ((N % H) ? 1 : 0));
        cout << s << "\n";
    }
}

int main()
{
    run();
    return 0;
}