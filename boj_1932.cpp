#include <cstdio>

using namespace std;

int num;
int triangle[125251];

void run();
int get_max(int r, int c);

int main()
{
    scanf("%d", &triangle[0]);
    num = triangle[0] * (triangle[0] + 1) / 2;
    for(int i = 1; i <= num; ++i)
        scanf("%d", &triangle[i]);
    
    run();
    
    return 0;
}

void run()
{
    int pos;
    for(int i = 2; i <= triangle[0]; ++i) {
        for(int j = 0; j < i; ++j) {
            pos = i * (i - 1) / 2 + 1 + j;
            triangle[pos] = get_max(i, j) + triangle[pos];
        }
    }

    pos = triangle[0] * (triangle[0] - 1) / 2 + 1;
    int max_cost = triangle[pos];
    for(; pos <= num; ++pos) {
        if(triangle[pos] > max_cost)
            max_cost = triangle[pos];
    }

    printf("%d\n", max_cost);
}

int get_max(int r, int c)
{
    bool left_exist = true;
    bool right_exist = true;
    int left_pos, right_pos;

    if(c == 0)
        left_exist = false;
    if(c == r - 1)
        right_exist = false;

    left_pos = (r - 1) * (r - 2) / 2 + 1 + c - 1;
    right_pos = (r - 1) * (r - 2) / 2 + 1 + c;

    if(left_exist && right_exist) {
        return (triangle[left_pos] < triangle[right_pos]) ? triangle[right_pos] : triangle[left_pos];
    }
    else {
        if(left_exist) {
            return triangle[left_pos];
        }
        if(right_exist) {
            return triangle[right_pos];
        }
    }
}