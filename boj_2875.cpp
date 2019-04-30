// boj_2875

#include <cstdio>

using namespace std;

int main()
{
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);

    int team_count = 0;
    int rm = m, rn = n;
    while(rm > 0) {
        if(rn < 2)
            break;
        rm--;
        rn -= 2;
        team_count++;
    }

    if(rm + rn >= k) {
        printf("%d\n", team_count);
    }
    else {
        k -= (rm + rn);
        m -= rm;
        n -= rn;
        while(k > 0) {
            n -= 2;
            m--;
            team_count--;
            if(n <= 0 || m <= 0)
                break;
            k -= 3;
        }

        printf("%d\n", team_count);
    }
    
    return 0;
}