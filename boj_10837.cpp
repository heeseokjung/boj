#include <stdio.h>
#include <utility>
using namespace std;

int k, c;
pair<int, int> query[100000];

void input()
{
    scanf("%d %d", &k, &c);
    int m, n;
    for(int i = 0; i < c; ++i) {
        scanf("%d %d", &m, &n);
        query[i] = make_pair(m, n);
    }
}

void run()
{
    int m, n, is_possible;
    for(int i = 0; i < c; ++i) {
        m = query[i].first;
        n = query[i].second;
        if(m == n) {
            is_possible = 1;
        }
        else if(m > n) {
            if(n + k - m + 2 < m)
                is_possible = 0;
            else
                is_possible = 1;
        }
        else {
            if(m + k - n + 1 < n)
                is_possible = 0;
            else
                is_possible = 1;
        }
        printf("%d\n", is_possible);
    }
}

int main()
{
    input();
    run();

    return 0;
}