#include <cstdio>
#include <vector>
using namespace std;

int N;
vector<int> arr[3];

int main() {
    scanf("%d", &N);
    for(int i = 0; i < 3; ++i) {
        for(int j = 0; j < N; ++j) {
            scanf("%d", &arr[i][j]);
        }
    }
    return 0;
}