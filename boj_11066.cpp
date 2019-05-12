#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;

#define INF 1000000000
#define INVALID -1

int num_chapter;
int file[500];
int sum[500];
int dp[500][500];
vector<int> answer;

inline int get_partial_sum(int i, int j);
int run(int p, int r);

int main()
{
    int num_case;
    scanf("%d", &num_case);

    while(num_case--) {
        scanf("%d", &num_chapter);
        for(int i = 0; i < num_chapter; ++i)    
            scanf("%d", &file[i]);

        sum[0] = file[0];
        for(int i = 1; i < num_chapter; ++i)
            sum[i] = sum[i - 1] + file[i];

        for(int i = 0; i < num_chapter; ++i) 
            memset(dp[i], INVALID, sizeof(int) * num_chapter);

        answer.push_back(run(0, num_chapter - 1));
    }

    for(int i = 0; i < (int)answer.size(); ++i)
        printf("%d\n", answer[i]);
    
    return 0;
}

int run(int p, int r)
{
    if(dp[p][r] != INVALID) {
        return dp[p][r];
    }
    else if(p == r) {
        dp[p][r] = 0;
        return 0;
    }
    else if(p + 1 == r) {
        dp[p][r] = file[p] + file[r];
        return dp[p][r];
    }
    else {
        int m = INF;
        for(int q = p; q < r; ++q) {
            int tmp = run(p, q) + run(q + 1, r) + get_partial_sum(p, r);
            if(tmp < m)
                m = tmp;
        }
        dp[p][r] = m;
        return dp[p][r];
    }
}

inline int get_partial_sum(int i, int j)
{
    if(i == 0)
        return sum[j];
    else
        return sum[j] - sum[i - 1];
}