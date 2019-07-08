#include <stdio.h>
#include <iostream>
#include <string>
#include <list>
using namespace std;

int n;
string str;
char cmd, ins;
list<char>::iterator p;

void run()
{
    cin >> str;
    getchar();
    scanf("%d", &n);
    getchar();

    list<char> lt(str.begin(), str.end());
    p = lt.end();
    
    while(n--) {
        scanf("%c", &cmd);
        switch(cmd) {
            case 'L':
                if(p == lt.begin())
                    break;
                p--;
                break;
            case 'D':
                if(p == lt.end())
                    break;
                p++;
                break;
            case 'B':
                if(p == lt.begin())
                    break;
                p--;
                p = lt.erase(p);
                break;
            case 'P':
                scanf(" %c", &ins);
                p = lt.insert(p, ins);
                p++;
                break;
            default:
                break;
        }
        getchar();
    }

    for(p = lt.begin(); p != lt.end(); ++p)
        printf("%c", *p);
    printf("\n");
}

int main()
{
    run();

    return 0;
}