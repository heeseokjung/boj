#include <cstdio>

using namespace std;

int r[3];

bool is_arithmetic_sequence(int x)
{
    if(x < 100)
        return true;
    else if (x == 1000)
        return false;
    
    int i = 0;
    while(x) {
        r[i++] = x % 10;
        x /= 10;
    }

    return (r[2] - r[1]) == (r[1] - r[0]);
}

int main()
{
    int n;
    scanf("%d", &n);

    
    int count = 0;
    for(int i = 1; i <= n; ++i) {
        if(is_arithmetic_sequence(i))
            count++;
    }

    printf("%d\n", count);

    return 0;
}