#include <cstdio>
#include <utility>

using namespace std;

int N;
int arr[65][65];

void run(pair<int, int> p1, pair<int, int> p2);

int main()
{
    scanf("%d", &N);
    char number;
    for(int i = 1; i <= N; ++i) {
        for(int j = 1; j <= N; ++j) {
            scanf(" %c", &number);
            arr[i][j] = number - '0';
        }   
    }

    run(make_pair(1, 1), make_pair(N, N));
    printf("\n");
    
    return 0;
}

void run(pair<int, int> p1, pair<int, int> p2)
{   
    int tmp = arr[p1.first][p1.second];
    bool check = true;
    for(int i = p1.first; i <= p2.first; ++i) {
        if(check) {
            for(int j = p1.second; j <= p2.second; ++j) {
                if(arr[i][j] != tmp) {
                    check = false;
                    break;
                }
            }
        }
        else
            break;
    }

    if(check) {
        printf("%d", tmp);
    }
    else {
        printf("(");
        int mid_row = (p1.first + p2.first) / 2;
        int mid_col = (p1.second + p2.second) / 2;
        run(p1, make_pair(mid_row, mid_col));
        run(make_pair(p1.first, mid_col + 1), make_pair(mid_row, p2.second));
        run(make_pair(mid_row + 1, p1.second), make_pair(p2.first, mid_col));
        run(make_pair(mid_row + 1, mid_col + 1), p2);
        printf(")");
    }
}