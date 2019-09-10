#include <stdio.h>
#include <stack>
#include <utility>
using namespace std;

int N;
int num[500000];
long long count = 0;

void input()
{
    scanf("%d", &N);
    for(int i = 0; i < N; ++i)
        scanf("%d", num + i);
}

void run()
{
    stack<pair<int, long long> > s;
    for(int i = 0; i < N; ++i) {
        if(s.empty()) {
            s.push(pair<int, long long>(num[i], 1));
        } 
        else if(s.top().first > num[i]) {
            count++;
            s.push(pair<int, long long>(num[i], 1));
        } 
        else {
            pair<int, long long> p(num[i], 1);
            while(!s.empty() && s.top().first <= num[i]) {
                count += s.top().second;
                if(s.top().first == num[i])
                    p.second += s.top().second;
                s.pop();
            }
            if(!s.empty())
                count++;
            s.push(p);
        }
    }
    printf("%lld\n", count);
}

int main()
{
    input();
    run();
    return 0;
}