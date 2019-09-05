#include <stdio.h>
#include <stack>
using namespace std;

int N;
int height[500001];

void input()
{
    scanf("%d", &N);
    for(int i = 1; i <= N; ++i)
        scanf("%d", &height[i]);
}

void run()
{
    stack<int> s;
    for(int i = 1; i <= N; ++i) {
        if(s.empty()) {
            printf("0 ");
        }
        else if(height[s.top()] > height[i]) {
            printf("%d ", s.top());
        }
        else {
            while(!s.empty() && height[s.top()] <= height[i])
                s.pop();
            if(s.empty())
                printf("0 ");
            else
                printf("%d ", s.top());
        }
        s.push(i);
    }
    printf("\n");
}

int main()
{
    input();
    run();
    return 0;
}