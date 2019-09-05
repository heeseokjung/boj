#include <stdio.h>
#include <utility>
#include <vector>
using namespace std;

int field[10][10];
int K, ans = -1;
int paper[6] = {0, 5, 5, 5, 5, 5};
vector<pair<int, int> > target;

void input()
{
	for(int i = 0; i < 10; ++i) {
		for(int j = 0; j < 10; ++j) {
			scanf("%d", &field[i][j]);
			if(field[i][j])
				target.push_back(pair<int, int>(i, j));
		}
	}
	K = (int)target.size();
}

bool check(int r, int c, int size)
{
	if(r + size > 10 || c + size > 10)
		return false;
	for(int i = r; i < r + size; ++i) {
		for(int j = c; j < c + size; ++j) {
			if(!field[i][j])
				return false;
		}
	}
	return true;
}

void put(int r, int c, int size, int p) 
{
	for(int i = r; i < r + size; ++i) {
		for(int j = c; j < c + size; ++j) {
			field[i][j] = p;	
		}
	}
}

void dfs(int pos, int cnt)
{
	if(pos == K) {
		if(ans < 0 || cnt < ans)
			ans = cnt;
		return;
	}
	
	int r = target[pos].first;
	int c = target[pos].second;
	if(field[r][c]) {
		for(int i = 5; i > 0; --i) {
			if(paper[i] > 0 && check(r, c, i)) {
				put(r, c, i, 0);
				--paper[i];
				dfs(pos + 1, cnt + 1);
				++paper[i];
				put(r, c, i, 1);
			}
		}
	}
	else {
		dfs(pos + 1, cnt);
	}
}

void run()
{
	dfs(0, 0);
	printf("%d\n", ans);
}

int main()
{
	input();
	run();
	return 0;
}