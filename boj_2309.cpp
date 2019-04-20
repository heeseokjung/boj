// boj_2309

#include <cstdio>
#include <algorithm>

using namespace std;

#define HUNDREAD 100

int height[9];
int comb[9] = {0, 0, 1, 1, 1, 1, 1, 1, 1};

int main()
{
    for(int i = 0; i < 9; ++i)
        scanf("%d", height + i);

    sort(height, height + 9);

    int sum;
    do {
        sum = 0;
        for(int i = 0; i < 9; ++i) {
            if(comb[i])
                sum += height[i];
        }
        if(sum == HUNDREAD) {
            for(int i = 0; i < 9; ++i) {
                if(comb[i])
                    printf("%d\n", height[i]);
            }
            break;
        }
    } while(next_permutation(comb, comb + 9));

    return 0;
}