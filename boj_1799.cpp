#include <cstdio>
#include <utility>
#include <vector>
using namespace std;

int N;
int arr[10][10];
bool visit[10][10];
bool ld[20], rd[20];
int black_size, white_size;
int black_ans = 0, white_ans = 0;
vector<pair<int, int> > black, white;

void dfs1(int pos, int count) {
    if(pos == black_size) {
        black_ans = (black_ans < count) ? count : black_ans;
        return;
    }
    int r = black[pos].first;
    int c = black[pos].second;
    if(arr[r][c] && !ld[r-c+N-1] && !rd[r+c] && !visit[r][c]) {
        ld[r-c+N-1] = rd[r+c] = true;
        dfs1(pos+1, count+1);
        ld[r-c+N-1] = rd[r+c] = false;
    }
    dfs1(pos+1, count);
}

void dfs2(int pos, int count) {
    if(pos == white_size) {
        white_ans = (white_ans < count) ? count : white_ans;
        return;
    }
    int r = white[pos].first;
    int c = white[pos].second;
    if(arr[r][c] && !ld[r-c+N-1] && !rd[r+c] && !visit[r][c]) {
        ld[r-c+N-1] = rd[r+c] = true;
        dfs2(pos+1, count+1);
        ld[r-c+N-1] = rd[r+c] = false;
    }
    dfs2(pos+1, count);
}

int main() {
    scanf("%d", &N);
    for(int i = 0; i < N; ++i)
        for(int j = 0; j < N; ++j)
            scanf("%d", &arr[i][j]);
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            if(i % 2) {
                if(j % 2)
                    black.push_back(pair<int, int>(i, j));
                else
                    white.push_back(pair<int, int>(i, j));
            }
            else {
                if(j % 2)
                    white.push_back(pair<int, int>(i, j));
                else
                    black.push_back(pair<int, int>(i, j));
            }
        }
    }
    black_size = (int)black.size();
    white_size = (int)white.size();
    dfs1(0, 0);
    dfs2(0, 0);
    printf("%d\n", black_ans + white_ans);
    return 0;
}