#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int x1, y1, p1, q1;
int x2, y2, p2, q2;
vector<char> ans;

void input()
{
    scanf("%d %d %d %d", &x1, &y1, &p1, &q1);
    scanf("%d %d %d %d", &x2, &y2, &p2, &q2);
    getchar();
}

void run()
{
    ans.reserve(4);
    for(int i = 0; i < 4; ++i) {
        input();
        int w = min(p1, p2) - max(x1, x2);
        int h = min(q1, q2) - max(y1, y2);
        if(w == 0 && h == 0)
            ans.push_back('c');
        else if(w == 0 || h == 0)
            ans.push_back('b');
        else if(w < 0 || h < 0)
            ans.push_back('d');
        else
            ans.push_back('a');
    }
    for(int i = 0; i < 4; ++i)
        printf("%c\n", ans[i]);
}

int main()
{
    run();
    return 0;
}