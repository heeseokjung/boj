#include <stdio.h>
#include <utility>
#include <vector>
using namespace std;

int R, C;
int num[1001][1001];
vector<char> v1, v2;

void input()
{
    scanf("%d %d", &R, &C);
    for(int i = 1; i <= R; ++i) {
        for(int j = 1; j <= C; ++j)
            scanf("%d", &num[i][j]);
    }
}

void move(pair<int, int>& p, int d)
{
    switch(d) {
        case 0:
            for(int i = 0; i < C - 1; ++i)
                v1.push_back('R');
            v1.push_back('D');
            for(int i = 0; i < C - 1; ++i)
                v1.push_back('L');
            v1.push_back('D');
            p.first += 2;
            break;
        case 1:
            for(int i = 0; i < C - 1; ++i)
                v2.push_back('R');
            v2.push_back('D');
            for(int i = 0; i < C - 1; ++i)
                v2.push_back('L');
            v2.push_back('D');
            p.first -= 2;
            break;
        case 2:
            v1.push_back('D'); v1.push_back('R');
            v1.push_back('U'); v1.push_back('R');
            p.second += 2;
            break;
        case 3:
            v2.push_back('D'); v2.push_back('R');
            v2.push_back('U'); v2.push_back('R');
            p.second -= 2;
            break;
        default:
            break;
    }
}

void run()
{
    if(R % 2) {
        for(int i = 0; i < R; ++i) {
            if(i % 2) {
                for(int j = 0; j < C - 1; ++j)
                    printf("L");
            } 
            else {
                for(int j = 0; j < C - 1; ++j)
                    printf("R");
            }
            i != R - 1 ? printf("D") : printf("\n");
        }
    }
    else if(C % 2) {
        for(int i = 0; i < C; ++i) {
            if(i % 2) {
                for(int j = 0; j < R - 1; ++j)
                    printf("U");
            } 
            else {
                for(int j = 0; j < R - 1; ++j)
                    printf("D");
            }
            i != C - 1 ? printf("R") : printf("\n");
        }
    }
    else {
        int _r = 1, _c = 2;
        for(int i = 1; i <= R; ++i) {
            for(int j = 1; j <= C; ++j) {
                if((i + j) % 2 && num[_r][_c] > num[i][j]) {
                    _r = i; _c = j;
                }
            }
        }

        pair<int, int> p1 = pair<int, int>(1, 1);
        pair<int, int> p2 = pair<int, int>(R, C);
        while(p1.first + 1 < _r)
            move(p1, 0);
        while(p2.first - 1 > _r)
            move(p2, 1);
        while(p1.second + 1 < _c)
            move(p1, 2);
        while(p2.second - 1 > _c)
            move(p2, 3);

        if(p1.first == _r) {
            v1.push_back('D'); v1.push_back('R');
        }
        else {
            v1.push_back('R'); v1.push_back('D');
        }
        for(int i = 0; i < (int)v1.size(); ++i)
            printf("%c", v1[i]);
        for(int i = (int)v2.size() - 1; i >= 0; --i)
            printf("%c", v2[i]);
        printf("\n");
    }
}

int main()
{
    input();
    run();
    return 0;
}