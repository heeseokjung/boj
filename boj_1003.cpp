#include <cstdio>
#include <vector>
#include <string.h>

using namespace std;

#define INVALID -1

int num_test_case;
int m_one[41], m_zero[41];
vector<int> test_case;

void run();
int dp_zero(int n);
int dp_one(int n);

int main()
{
    scanf("%d", &num_test_case);
    int n;
    for(int i =  0; i < num_test_case; ++i) {
        scanf("%d", &n);
        test_case.push_back(n);
    }

    run();
    
    return 0;
}

void run()
{
    memset(m_zero, INVALID, sizeof(m_zero));
    memset(m_one, INVALID, sizeof(m_one));
    m_zero[0] = 1; m_zero[1] = 0;
    m_one[0] = 0; m_one[1] = 1;

    for(int i = 0; i < num_test_case; ++i) {
        int n = test_case[i];

        int zero_count = dp_zero(n);
        int one_count = dp_one(n);

        printf("%d %d\n", zero_count, one_count);
    }
}

int dp_zero(int n)
{
    if(n == 0)
        return m_zero[0];
    else if(n == 1)
        return m_zero[1];
    else if(m_zero[n] != INVALID)
        return m_zero[n];
    else {
        m_zero[n] = dp_zero(n - 1) + dp_zero(n - 2);
        return m_zero[n];
    }
}

int dp_one(int n)
{
    if(n == 0)
        return m_one[0];
    else if(n == 1)
        return m_one[1];
    else if(m_one[n] != INVALID)
        return m_one[n];
    else {
        m_one[n] = dp_one(n - 1) + dp_one(n - 2);
        return m_one[n]; 
    }
}