// boj_2798

#include <cstdio>
#include <algorithm>

using namespace std;

int n, m;
int max_sum = 0;
int card[100];
int comb[100];

void run();

int main()
{
    scanf("%d %d", &n, &m);
    int number;
    for(int i = 0; i < n; ++i) {
        scanf("%d", &number);
        card[i] = number;
        if(i < n - 3)
            comb[i] = 0;
        else
            comb[i] = 1;
    }

    run();
    
    return 0;
}

void run()
{
    do {
        int sum = 0;
        for(int i = 0; i < n; ++i) {
            if(comb[i]) {
                sum += card[i];
            if(sum > m)
                break;
            }  
        }
        
        if(max_sum < sum && sum <= m)
            max_sum = sum;
    } while(next_permutation(comb, comb + n));

    printf("%d\n", max_sum);
}