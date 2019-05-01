#include <cstdio>
#include <vector>
#include <stack>

using namespace std;

int size;
int histogram[100001];
vector<long long> answer;

long long calculate_max();

int main()
{
    while(true) {
        scanf("%d", &size);

        if(size == 0)
            break;
        
        for(int i = 0; i < size; ++i)
            scanf("%d", histogram + i);
        
        long long max_area = calculate_max();
        answer.push_back(max_area);
    }

    for(int i = 0; i < (int)answer.size(); ++i)
        printf("%lld\n", answer[i]);
    
    return 0;
}

long long calculate_max()
{
    long long max_area = 0;
    stack<long long> s;

    for(int i = 0; i < size; ++i) {
        long long x = i;
        while(!s.empty() && histogram[s.top()] > histogram[x]) {
            long long height = histogram[s.top()];
            s.pop();
            long long right = x - 1;
            long long left = 0;
            if(!s.empty())
                left = s.top() + 1;
            long long width = (right - left) + 1;

            if(height * width > max_area)
                max_area = height * width;
        }
        s.push(x);
    }
    
    while(!s.empty()) {
        long long height = histogram[s.top()];
        s.pop();
        long long left = 0;
        if(!s.empty())
            left = s.top() + 1;
        long long width = ((size - 1) - left) + 1;
        
        if(height * width > max_area)
            max_area = height * width;
    }

    return max_area;
}