#include <cstdio>
#include <utility>
#include <vector>
using namespace std;

int main() {
    int A, B, C;
    scanf("%d %d %d", &A, &B, &C);
    vector<pair<int, int> > truck(3);
    for(int i = 0; i < 3; ++i)
        scanf("%d %d", &truck[i].first, &truck[i].second);
    
    int count[101];
    for(int i = 1; i <= 100; ++i)
        count[i] = 0;
    for(int i = 0; i < 3; ++i) {
        for(int j = truck[i].first; j < truck[i].second; ++j)
            count[j]++;
    }

    int sum = 0;
    for(int i = 1; i <= 100; ++i) {
        switch(count[i]) {
            case 1:
                sum += A;
                break;
            case 2:
                sum += B*2;
                break;
            case 3:
                sum += C*3;
                break;
            default:
                break;
        }
    }
    printf("%d\n", sum);

    return 0;
}