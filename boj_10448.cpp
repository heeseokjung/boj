#include <stdio.h>
#include <vector>
using namespace std;

int tc;
bool is_valid[1001] = {false, };
vector<int> triangular;

void run()
{
    triangular.reserve(45);
    for(int i = 1; i <= 45; ++i)
        triangular.push_back(i*(i+1)/2);

    int sum;
    for(int i = 0; i < 45; ++i) {
        for(int j = 0; j < 45; ++j) {
            for(int k = 0; k < 45; ++k) {
                sum = triangular[i] + triangular[j] + triangular[k];
                if(sum <= 1000)
                    is_valid[sum] = true;
            }
        }
    }
    
    scanf("%d", &tc);
    int k;
    while(tc--) {
        scanf("%d", &k);
        if(is_valid[k])
            printf("1\n");
        else
            printf("0\n");
    }
}

int main()
{
    run();
    return 0;
}