#include <stdio.h>
#include <set>
#include <vector>

using namespace std;

int n, m;
set<int> s;
vector<int> query;

void input()
{
    scanf("%d", &n);
    int x;
    for(int i = 0; i < n; ++i) {
        scanf("%d", &x);
        s.insert(x);
    }
    scanf("%d", &m);
    query.reserve(m);
    for(int i = 0; i < m; ++i) {
        scanf("%d", &x);
        query.push_back(x);
    }
}

void run()
{
    for(int i = 0; i < m; ++i) {
        if(s.find(query[i]) != s.end())
            printf("1\n");
        else 
            printf("0\n");
    }
}

int main()
{
    input();
    run();
    
    return 0;
}