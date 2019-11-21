#include <cstdio>
#include <utility>
#include <vector>
using namespace std;

int N, M;
int arr[300];
vector<int> ans; 
#define INF 1000

int main() {
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; ++i)
        scanf("%d", arr+i);
    int p = 1, q = N*100, m;
    int mn = 30000;
    while(p < q) {
        m = (p+q)/2;
        int sum = 0, count = 0;
        for(int i = 0; i < N; ++i) {
            if(arr[i] > m) {
                count = INF;
                break;
            }
            else if(sum + arr[i] <= m) {
                sum += arr[i];
            }
            else {
                count++;
                if(sum == 0)
                    count = INF;
                sum = arr[i];
            }
        }
        if(count+1 <= M) {
            q = m;
            mn = (m < mn) ? m : mn;
        }
        else {
            p = m+1;
        }
    }
    printf("%d\n", mn);
    int sum = 0, count = 0;
    for(int i = 0; i < N; ++i) {
        if(sum + arr[i] <= mn) {
            sum += arr[i];
            count++;
            if(i == N-1) {
                ans.push_back(count);
                count = 0;
            }
        }
        else {
            ans.push_back(count);
            sum = arr[i];
            count = 1;
        }
    }
    if(count > 0)
        ans.push_back(count);
    int size = (int)ans.size();
    int diff = (size < M) ? M - size : size - M;
    for(int i = 0; i < size; ++i) {
        while(diff > 0 && ans[i] >= 2) {
            printf("1 ");
            diff--; ans[i]--;
        }
        printf("%d ", ans[i]);
    }
    printf("\n");
    return 0;
}