#include <stdio.h>
#include <vector>

using namespace std;

long long pseq[101] = {0, };
vector<long long> ans;

long long get_num(int n);

int main()
{
    int num_case;
    scanf("%d", &num_case);

    pseq[1] = 1; pseq[2] = 1; pseq[3] = 1; pseq[4] = 2; pseq[5] = 2;

    int n;
    while(num_case--) {
        scanf("%d", &n);
        ans.push_back(get_num(n));
    }


    for(int i = 0; i < (int)ans.size(); ++i)
        printf("%lld\n", ans[i]);
    
    return 0;
}

long long get_num(int n)
{
    if(pseq[n] != 0) {
        return pseq[n];
    }
    else if(6 <= n && n <= 8) {
        pseq[n] = get_num(9 - n) + get_num(n - 1);
        return pseq[n];
    }
    else if(n >= 9) {
        pseq[n] = get_num(n - 5) + get_num(n - 1); 
        return pseq[n];
    }
}