#include <stdio.h>
#include <utility>
#include <vector>
using namespace std;

int K;
char wheel[5][9];
vector<pair<int, int> > query;
#define CLOCK_WISE 1
#define COUNTER_CLOCK_WISE -1

void input()
{
    for(int i = 1; i <= 4; ++i) {
        fgets(wheel[i], sizeof(char[9]), stdin);
        getchar();
    }
    scanf("%d", &K);
    query.reserve(K);
    int x, y;
    for(int i = 0; i < K; ++i) {
        scanf("%d %d", &x, &y);
        query.push_back(pair<int, int>(x, y));
    }
}

void rotate(int target, int direction)
{
    char tmp;
    switch(direction) {
        case CLOCK_WISE:
            tmp = wheel[target][7];
            for(int i = 7; i > 0; --i)
                wheel[target][i] = wheel[target][i-1];
            wheel[target][0] = tmp;    
            break;
        case COUNTER_CLOCK_WISE:
            tmp = wheel[target][0];
            for(int i = 0; i < 7; ++i)
                wheel[target][i] = wheel[target][i+1];
            wheel[target][7] = tmp;
            break;
        default:
            break;
    }
}

void propagate(int target, int direction)
{
    const int l = 6, r = 2;
    char left = wheel[target][l], right = wheel[target][r];
    int t = target, d = direction;
    while(t > 1) {
        if(left == wheel[t-1][r])
            break;
        left = wheel[t-1][l];
        rotate(t - 1, -d);
        --t;
        d = -d;
    }
    t = target, d = direction;
    while(t < 4) {
        if(right == wheel[t+1][l])
            break;
        right = wheel[t+1][r];
        rotate(t + 1, -d);
        ++t;
        d = -d;
    }
    rotate(target, direction);
}

int calculate_score()
{
    int score = 0;
    score += wheel[1][0] - '0' ? 1 : 0;
    score += wheel[2][0] - '0' ? 2 : 0;
    score += wheel[3][0] - '0' ? 4 : 0;
    score += wheel[4][0] - '0' ? 8 : 0;
    return score;
}

void run()
{
    for(int i = 0; i < K; ++i) 
        propagate(query[i].first, query[i].second);

    printf("%d\n", calculate_score());
}

int main()
{
    input();
    run();
    return 0;
}