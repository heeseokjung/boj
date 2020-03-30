#include <cstdio>
#include <vector>
using namespace std;

int N, B;
vector<int> v;
int left[100000];
int right[10000];

int main() {
    scanf("%d %d", &N, &B);
    v = vector<int>(N);
    for(int i = 0; i < N; ++i)
        scanf("%d", &v[i]);
    int pos;
    for(int i = 0; i < N; ++i) {
        if(v[i] == B) {
            pos = i;
            break;
        }
    }
    return 0;
}