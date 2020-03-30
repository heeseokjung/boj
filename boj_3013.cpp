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

    // LET delat(x): 수열 x의 B보다 큰원소의 갯수 - B보다 작은 원소의 갯수
    // B로 끝나는 모든 부분수열의 delta값을 left배열에 저장
    // B에서 시작하는 모든 부분수열의 delta값을 right배열에 저장
    // [-N, N]에 대해 
    return 0;
}