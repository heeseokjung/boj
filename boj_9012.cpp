#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
using namespace std;

int tc;
vector<string> v;

void input()
{
    scanf("%d", &tc);
    getchar();
    int tmp = tc;
    while(tmp--) {
        string s;
        getline(cin, s);
        v.push_back(s);
    }
}

void run()
{
    int check = 0;
    for(int i = 0; i < tc; ++i) {
        check = 0;
        for(int j = 0; j < v[i].length(); ++j) {
            if(v[i][j] == '(')
                check++;
            else if(v[i][j] == ')')
                check--;
            if(check < 0)
                break;
        }
        if(check == 0)
            printf("YES\n");
        else
            printf("NO\n");
    }
}


int main()
{
    input();
    run();

    return 0;
}