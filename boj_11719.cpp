#include <stdio.h>

int p = 0, q = 0;
char str[100][105];

void input()
{
    char c;
    while(true) {
        if(scanf("%c", &c) == EOF) {
            break;
        }
        else if(c == '\n') {
            str[p++][q] = '\0';
            q = 0;
        }
        else {
            str[p][q++] = c;
        }
    }
}

void run()
{
    for(int i = 0; i < p; ++i) {
        printf("%s\n", str[i]);
    }
}

int main()
{
    input();
    run();
    return 0;
}