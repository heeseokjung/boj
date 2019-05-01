#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int num_house, num_router;
vector<int> house;

int run();

int main()
{
    scanf("%d %d", &num_house, &num_router);
    house.reserve(num_house);
    int location;
    for(int i = 0 ; i < num_house; ++i) {
        scanf("%d", &location);
        house.push_back(location);
    }

    sort(house.begin(), house.end());

    int max_dist = run();

    printf("%d\n", max_dist);
    
    return 0;
}

int run()
{
    int p = 1;
    int r = house.back() - house.front();
    int q;
    int max_dist;

    while(p < r) {
        q = (p + r) / 2;
        int count = 1;
        int prev = 0;
        for(int i = 0; i < (int)house.size(); ++i) {
            if(house[i] - house[prev] >= q) {
                count++;
                prev = i;
            }
        }

        if(count >= num_router) {
            max_dist = q;
            p = q + 1;
        }
        else {
            r = q;
        }
    }

    return max_dist;
}