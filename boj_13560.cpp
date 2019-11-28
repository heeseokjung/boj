#include <cstdio>
#include <algorithm>
using namespace std;

int N;
int score[10001];

int main() {
    scanf("%d", &N);
    int total = 0;
    for(int i = 0; i < N; ++i) {
        scanf("%d", score+i);
        total += score[i];
    }
    if(total != N*(N-1)/2) {
        printf("-1\n");
        return 0;
    }
    sort(score, score+N);
    bool is_valid = true;
    int sum = 0;
    for(int i = 0; i < N; ++i) {
        sum += score[i];
        if(sum < i*(i+1)/2) {
            is_valid = false;
            break;
        }
    }
    printf("%d\n", is_valid ? 1 : -1);
    return 0;
}