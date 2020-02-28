#include <cstdio>
#include <set>
using namespace std;

int N;
int arr[1000][5];
set<int> s[1000];

int main() {
    scanf("%d", &N);
    for(int i = 0; i < N; ++i)
        for(int j = 0; j < 5; ++j)
            scanf("%d", &arr[i][j]);
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < 5; ++j) {
            for(int k = 0; k < N; ++k) {
                if(k == i)
                    continue;
                if(arr[i][j] == arr[k][j] && s[i].find(k) == s[i].end())
                    s[i].insert(k);
            }
        }
    }
    int count = -1, ans;
    for(int i = 0; i < N; ++i) {
        if((int)s[i].size() > count) {
            count = s[i].size();
            ans = i+1;
        }
    }
    printf("%d\n", ans);
    return 0;
}