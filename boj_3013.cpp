#include <cstdio>
#include <vector>
using namespace std;

int N, B;
vector<int> v;
int left[200001];
int right[200001];
int diff = 0;

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

    diff = 0;
    for(int i = pos; i >= 0; --i) {
        if(v[i] > B)
            diff++;
        else if(v[i] < B)
            diff--;
        left[N+diff]++;
    }

    diff = 0;
    for(int i = pos; i < N; ++i) {
        if(v[i] > B)
            diff++;
        else if(v[i] < B)
            diff--;
        right[N+diff]++;
    }

    int sum = 0;
    for(int i = -N; i <= N; ++i) 
        sum += left[N+i] * right[N-i];
    printf("%d\n", sum);

    return 0;
}