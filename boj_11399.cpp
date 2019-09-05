#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> time;

int main()
{
    int num_people;
    scanf("%d", &num_people);

    int t;
    for(int i = 0; i < num_people; ++i) {
        scanf("%d", &t);
        time.push_back(t);
    }

    sort(time.begin(), time.end());

    int current_wait= 0, total_wait = 0;
    for(int i = 0; i < num_people; ++i) {
        total_wait = total_wait + current_wait + time[i];
        current_wait += time[i];
    }

    printf("%d\n", total_wait);
    
    return 0;
}