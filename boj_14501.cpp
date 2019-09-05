#include <cstdio>
#include <vector>

using namespace std;

int N;
int max_profit = -1;
int time[16];
int price[16];

void run(int day, int sum);

int main()
{
    scanf("%d", &N);
    int t, p;
    for(int i = 1; i <= N; ++i) {
        scanf("%d %d", &t, &p);
        time[i] = t;
        price[i] = p;
    }

    run(1, 0);

    printf("%d\n", max_profit);
    
    return 0;
}

void run(int day, int sum)
{
    if(day == N + 1) {
        if(sum > max_profit)
            max_profit = sum;
        return;
    }

    if(day + time[day] - 1 <= N)
        run(day + time[day], sum + price[day]);
    if(day <= N)
        run(day + 1, sum);
}