#include <stdio.h>
#include <utility>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;
int min_a = 1000000000, max_b = -1;
typedef struct Bus
{
    int bid;
    pair<int, int> p;
    int direction;
}Bus;
vector<Bus> clock_route;
vector<Bus> counter_clock_route;
bool is_covered[500001] = {false, };

void input()
{
    scanf("%d %d", &n, &m);
    int a, b, d;
    clock_route.reserve(m/2);
    counter_clock_route.reserve(m/2);
    for(int i = 1; i <= m; ++i) {
        scanf("%d %d", &a, &b);
        d = (a < b) ? 1 : 0;
        Bus bus;
        bus.bid = i;
        bus.p = make_pair(a, b);
        bus.direction = d;
        if(d) {
            clock_route.push_back(bus);
        }
        else {
            counter_clock_route.push_back(bus);
            min_a = min(min_a, a);
            max_b = max(max_b, b);
        }
    }
}

bool comp(Bus& x, Bus& y)
{
    if(x.p.first < y.p.first)
        return true;
    else if(x.p.first == y.p.first)
        return x.p.second > y.p.second;
    else
        return false;
}

void run()
{
    sort(clock_route.begin(), clock_route.end(), comp);
    int dest_max = -1, size = (int)clock_route.size();
    for(int i = 0; i < size; ++i) {
        if(dest_max != -1 && clock_route[i].p.second <= dest_max)
            is_covered[clock_route[i].bid] = true;
        dest_max = max(dest_max, clock_route[i].p.second);
    }

    sort(counter_clock_route.begin(), counter_clock_route.end(), comp);
    dest_max = -1, size = (int)counter_clock_route.size();
    for(int i = 0; i < size; ++i) {
        if(dest_max != -1 && counter_clock_route[i].p.second <= dest_max)
            is_covered[counter_clock_route[i].bid] = true;
        dest_max = max(dest_max, counter_clock_route[i].p.second);
    }

    size = (int)clock_route.size();
    for(int i = 0; i < size; ++i) {
        if(min_a <= clock_route[i].p.first || max_b >= clock_route[i].p.second)
            is_covered[clock_route[i].bid] = true;
    }

    for(int i = 1; i <= m; ++i) {
        if(!is_covered[i])
            printf("%d ", i);
    }
    printf("\n");
}

int main()
{
    input();
    run();
    return 0;
}