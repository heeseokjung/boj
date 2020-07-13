#include <cstdio>
#include <utility>
#include <vector>
using namespace std;

int sudoku[9][9];
int ans[9][9];
bool is_found = false;
bool row[9][10];
bool col[9][10];
bool sector[9][10];
vector<pair<int, int> > v;

inline int get_sector(int r, int c) {
    if(r >= 0 && r <= 2) {
        if(c >= 0 && c <= 2)
            return 0;
        else if(c >= 3 && c <= 5)
            return 1;
        else
            return 2;
    } else if(r >= 3 && r <= 5) {
        if(c >= 0 && c <= 2)
            return 3;
        else if(c >= 3 && c <= 5)
            return 4;
        else
            return 5;
    } else {
        if(c >= 0 && c <= 2)
            return 6;
        else if(c >= 3 && c <= 5)
            return 7;
        else
            return 8;
    }
}

void backtrack(int pos) {
    if(pos == (int)v.size()) {
        for(int i = 0; i < (int)v.size(); ++i) {
            int r = v[i].first;
            int c = v[i].second;
            if(sudoku[r][c] == 0)
                return;
        }
        
        if(!is_found) {
            for(int i = 0; i < 9; ++i) 
                for(int j = 0; j < 9; ++j)
                    ans[i][j] = sudoku[i][j];
        }
    }

    int r = v[pos].first;
    int c = v[pos].second;
    int s = get_sector(r, c);
    for(int i = 1; i <= 9; ++i) {
        if(!row[r][i] && !col[c][i] && !sector[s][i]) {
            row[r][i] = col[c][i] = sector[s][i] = true;
            sudoku[r][c] = i;
            backtrack(pos + 1);
            sudoku[r][c] = 0;
            row[r][i] = col[c][i] = sector[s][i] = false;
        }
    }
}

int main() {
    for(int i = 0; i < 9; ++i)
        for(int j = 0; j < 9; ++j) 
            scanf("%d", &sudoku[i][j]);

    for(int i = 0; i < 9; ++i) {
        for(int j = 0; j < 9; ++j) {
            if(sudoku[i][j] == 0)
                v.push_back({i, j});
            row[i][sudoku[i][j]] = true;
            col[j][sudoku[i][j]] = true;
            sector[get_sector(i, j)][sudoku[i][j]] = true;
        }
    }
    
    backtrack(0);
    for(int i = 0; i < 9; ++i) {
        for(int j = 0; j < 9; ++j) {
            printf("%d ", ans[i][j]);
        }
        printf("\n");
    }

    return 0;
}