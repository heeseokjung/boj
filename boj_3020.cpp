#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int N, H;
vector<int> v1, v2;
int height[500001];

int main() {
    scanf("%d %d", &N, &H);
    int x;
    for(int i = 0; i < N; ++i) {
        scanf("%d", &x);
        if(i % 2)
            v2.push_back(x);
        else
            v1.push_back(x);
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    int v1_size = (int)v1.size();
    int v2_size = (int)v2.size();
    for(int i = 0, j = 1; i < v1_size; ++i) {
        while(j <= v1[i]) 
            height[j++] += (v1_size - i);
    }
    for(int i = 0, j = H; i < v2_size; ++i) {
        while(H-j+1 <= v2[i]) {
            height[j] += (v2_size - i);
            j--;
        }
    }
    int mn = N;
    for(int i = 1; i <= H; ++i)
        mn = (height[i] < mn) ? height[i] : mn;
    int count = 0;
    for(int i = 1; i <= H; ++i) {
        if(height[i] == mn)
            count++;
    }
    printf("%d %d\n", mn, count);
    return 0;
}