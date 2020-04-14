#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int N;
int arr[3][100000];
int count[3][100001];
bool erase[100000];
vector<int> col[100001];
vector<int> v;

int main() {
    scanf("%d", &N);
    for(int i = 0; i < 3; ++i) {
        for(int j = 0; j < N; ++j) {
            scanf("%d", &arr[i][j]);
            count[i][arr[i][j]]++;
            col[arr[i][j]].push_back(j);
        }
    }

    queue<int> q;
    for(int i = 0; i < N; ++i) {
        int num = arr[0][i];
        if(count[1][num] == 0 || count[2][num] == 0)
            q.push(num);
    }

    int ans = 0;
    while(!q.empty()) {
        int num = q.front();
        q.pop();
        for(int i = 0; i < col[num].size(); ++i) {
            int c = col[num][i];
            if(erase[c])
                continue;
            erase[c] = true;
            ans++;

            if(--count[0][arr[0][c]] <= 0)
                q.push(arr[0][c]);
            if(--count[1][arr[1][c]] <= 0)
                q.push(arr[1][c]);
            if(--count[2][arr[2][c]] <= 0)
                q.push(arr[2][c]);
        }
    }
    printf("%d\n", ans);

    return 0;
}