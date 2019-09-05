#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);

    int r;
    vector<int> rope;
    for(int i = 0 ; i < n; ++i) {
        scanf("%d", &r);
        rope.push_back(r);
    }

    sort(rope.begin(), rope.end(), greater<int>());

    int max_weight = 0;
    for(int i = 0; i < n; ++i) {
        if(rope[i] * (i + 1) > max_weight)
            max_weight = rope[i] * (i + 1);
    }

    printf("%d\n", max_weight);
    
    return 0;
}