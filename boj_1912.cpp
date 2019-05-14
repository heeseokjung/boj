#include <stdio.h>
#include <algorithm>

using namespace std;

int size;
int arr[100001];

void run();

int main()
{
    scanf("%d", &size);
    for(int i = 0; i < size; ++i)
        scanf("%d", &arr[i]);

    run();
    
    return 0;
}

void run()
{
    int sum = 0, max_sum = arr[0];
    for(int i = 0; i < size; ++i) {
        sum += arr[i];
        max_sum = max(sum, max_sum);
        if(sum < 0)
            sum = 0;
    }

    printf("%d\n", max_sum);
}