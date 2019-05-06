#include <cstdio>
#include <vector>

using namespace std;

int memo[11] = {0, };

int run(int n);

int main()
{
    int num_testcase;
    scanf("%d", &num_testcase);

    memo[1] = 1;
    memo[2] = 2;
    memo[3] = 4;

    int n;
    vector<int> test_case;
    for(int i = 0; i < num_testcase; ++i) {
        scanf("%d", &n);
        test_case.push_back(n);
    }

    for(int i = 0; i < num_testcase; ++i) {
        int n = test_case[i];
        if(memo[n] != 0) {
            printf("%d\n", memo[n]);
        }
        else {
            int ans = run(n);
            printf("%d\n", ans);
        }
    }

    return 0;
}

int run(int n)
{
    if(n >= 1 && n <= 3) {
        return memo[n];
    }
    else if(memo[n] != 0) {
        return memo[n];
    }
    else {
        return memo[n] = run(n - 1) + run(n - 2) + run(n - 3);
    }
}