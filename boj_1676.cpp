#include <cstdio>
#include <algorithm>
using namespace std;

int cal(int x, int y) {
    int count = 0;
    while(x >= y && x % y == 0) {
        count++;
        x /= y;
    }
    return count;
}

int main() {
    int N;
    scanf("%d", &N);

    int two = 0, five = 0;
    for(int i = 2; i <= N; ++i)
        two += cal(i, 2);
    for(int i = 5; i <= N; ++i)
        five += cal(i, 5);

    printf("%d\n", min(two, five));

    return 0;
}