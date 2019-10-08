#include <stdio.h>
#include <algorithm>
using namespace std;

int main() {
    int N;
    scanf("%d", &N);
    long long arr[5000];
    for(int i = 0; i < N; ++i)
        scanf("%lld", arr + i);
    sort(arr, arr + N);
    long long diff = 1e10;
    int ii, jj, kk;
    for(int i = 0; i < N - 2; ++i) {
        int j = i + 1, k = N - 1;
        while(j < k) {
            if(abs(arr[i] + arr[j] + arr[k]) < diff) {
                diff = abs(arr[i] + arr[j] + arr[k]);
                ii = i; jj = j; kk = k;
            }
            if(arr[i] + arr[j] + arr[k] > 0)
                --k;
            else
                ++j;
        }
        if(arr[ii] + arr[jj] + arr[kk] == 0)
            break; 
    }
    printf("%lld %lld %lld\n", arr[ii], arr[jj], arr[kk]);
}