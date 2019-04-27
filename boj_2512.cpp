// boj_2512

#include <cstdio>

using namespace std;

int num_region;
int total_budget, budget_sum = 0, max_budget = 0;
int max_limit = 0;
int budget[10000];

void run(int first, int last);

int main()
{
    scanf("%d", &num_region);
    for(int i = 0; i < num_region; ++i) {
        scanf("%d", budget + i);
        budget_sum += budget[i];
        if(budget[i] > max_budget)
            max_budget = budget[i];
    }
    scanf("%d", &total_budget);

    if(budget_sum <= total_budget) {
        printf("%d\n", max_budget);
    }
    else {
        run(0, total_budget);
        printf("%d\n", max_limit);
    }

    return 0;
}

void run(int first, int last)
{
    if(first == last)
        return;
    
    int mid = (first + last) / 2;

    int used = 0;
    for(int i = 0; i < num_region; ++i) {
        if(budget[i] < mid)
            used += budget[i];
        else
            used += mid;
    }

    if(used > total_budget) {
        run(first, mid);
    }
    else {
        if(mid > max_limit)
            max_limit = mid;
        run(mid + 1, last);
    }
}