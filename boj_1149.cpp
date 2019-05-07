#include <cstdio>

using namespace std;

#define RED 0
#define GREEN 1
#define BLUE 2

int num_house;
int red[1001];
int green[1001];
int blue[1001];
int dp[3][1001];

inline int get_min(int a, int b);
void run();

int main()
{
    scanf("%d", &num_house);
    for(int i = 1; i <= num_house; ++i)
        scanf("%d %d %d", &red[i], &green[i], &blue[i]);

    run();
    
    return 0;
}

void run()
{
    dp[RED][1] = red[1];
    dp[GREEN][1] = green[1];
    dp[BLUE][1] = blue[1];

    for(int i = 2; i <= num_house; ++i) {
        dp[RED][i] = get_min(dp[GREEN][i-1], dp[BLUE][i-1]) + red[i];
        dp[GREEN][i] = get_min(dp[RED][i-1], dp[BLUE][i-1]) + green[i];
        dp[BLUE][i] = get_min(dp[RED][i-1], dp[GREEN][i-1]) + blue[i];
    }

    int min_cost = dp[RED][num_house];
    if(dp[GREEN][num_house] < min_cost)
        min_cost = dp[GREEN][num_house];
    if(dp[BLUE][num_house] < min_cost)
        min_cost = dp[BLUE][num_house];

    printf("%d\n", min_cost);
}

inline int get_min(int a, int b)
{
    return (a < b) ? a : b;
}