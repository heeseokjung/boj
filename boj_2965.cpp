#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
    int p[3];
    scanf("%d %d %d", p, p+1, p+2);

    int count = 0;
    while(max(p[1] - p[0], p[2] - p[1]) > 1) {
        if(p[1] - p[0] < p[2] - p[1]) {
            p[0] = p[1];
            ++p[1];
        } else {
            p[2] = p[1];
            --p[1];
        }
        count++;
    }
    printf("%d\n", count);

    return 0;
}