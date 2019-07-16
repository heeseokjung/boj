#include <stdio.h>
#include <utility>
using namespace std;

int m;
pair<int, int> ratio[1000];
int type[1000];

void input()
{
    scanf("%d", &m);
    int x, y, z;
    for(int i = 0; i < m; ++i) {
        scanf("%d %d %d", &x, &y, &z);
        ratio[i] = make_pair(x, y);
        type[i] = z;
    }
}

void run()
{
    int rpm = 1, direction = 0;
    for(int i = 0; i < m; ++i) {
        rpm = (rpm / ratio[i].first) * ratio[i].second;
        if(type[i])
            direction = 1 - direction;
    }
    printf("%d %d\n", direction, rpm);
}

int main()
{
    input();
    run();
    return 0;
}