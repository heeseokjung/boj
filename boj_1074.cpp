#include <cstdio>
#include <utility>
#include <stdlib.h>

using namespace std;

int N, R, C;
pair<int, int> dest;
int count = 0;

void run(pair<int, int> p1, pair<int, int> p2);

int main()
{
    scanf("%d %d %d", &N, &R, &C);
    dest = make_pair(R, C);

    run(make_pair(0, 0), make_pair((1 << N) - 1, (1 << N) - 1));

    return 0;
}

void run(pair<int, int> p1, pair<int, int> p2) 
{   
    if(p1 == p2) {
        if(p1 == dest) {
            printf("%d\n", count);
            exit(0);
        }
        else {
            count++;
        }
        return;
    }

    int mid_row = (p1.first + p2.first) / 2;
    int mid_col = (p1.second + p2.second) / 2;
    int skip_area = (mid_row - p1.first + 1) * (mid_col - p1.second + 1);

    if(R <= mid_row) {
        if(C <= mid_col) { // Area 1
            run(p1, make_pair(mid_row, mid_col));
            run(make_pair(p1.first, mid_col + 1), make_pair(mid_row, p2.second));
            run(make_pair(mid_row + 1, p1.second), make_pair(p2.first, mid_col));
            run(make_pair(mid_row + 1, mid_col + 1), p2);
        }
        else { // Area 2
            count = count + skip_area;
            run(make_pair(p1.first, mid_col + 1), make_pair(mid_row, p2.second));
        }
    }

    else {
        if(C <= mid_col) { // Area 3
            count = count + 2*skip_area;
            run(make_pair(mid_row + 1, p1.second), make_pair(p2.first, mid_col));
        }
        else { // Area 4
            count = count + 3*skip_area;
            run(make_pair(mid_row + 1, mid_col + 1), p2);
        } 
    }
}