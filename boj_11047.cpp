#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    
    vector<int> money;
    money.reserve(n);
    int m;
    for(int i = 0; i < n; ++i) {
        scanf("%d", &m);
        money.push_back(m);
    }

    int sum = 0, count = 0;
    for(int i = n - 1; i >= 0; --i) {
        if(sum == k)
            break;
        while(sum + money[i] <= k) {
            sum += money[i];
            count++;
        }
    }

    printf("%d\n", count);
    
    return 0;
}