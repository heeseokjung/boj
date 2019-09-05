#include <stdio.h>
#include <stack>
using namespace std;

int TC, N;
int select[100001];
int dfs_num[100001] = {0, };
int dfs_low[100001] = {0, };
bool is_cycle[100001] = {false, };
int dfs_count = 1, count = 0;
stack<int> s;

void input()
{
	scanf("%d", &N);
	for(int i = 1; i <= N; ++i)
		scanf("%d", select + i);
}

void dfs(int x)
{
	dfs_low[x] = dfs_num[x] = dfs_count++;
	s.push(x);
	if(!dfs_num[select[x]]) {
		dfs(select[x]);
	}
	if(!is_cycle[select[x]] && dfs_low[select[x]] < dfs_low[x]) {
		dfs_low[x] = dfs_low[select[x]];
	}
	if(dfs_num[x] == dfs_low[x]) {
		int t, n = 0;
		while(true) {
			t = s.top();
			s.pop();
			if(!is_cycle[t]) {
				is_cycle[t] = true;
				++n;
			}
			if(t == x)
				break;
		}
		if(n == 1 && x != select[x]) {
			is_cycle[x] = false;
			--n;
		}
		count += n;
	}
}

void run()
{
	scanf("%d", &TC);
	while(TC--) {
		input();
		for(int i = 1; i <= N; ++i) {
			if(!dfs_low[i]) 
				dfs(i);
		}
		printf("%d\n", N - count);
		for(int i = 1; i <= N; ++i) {
			dfs_num[i] = 0;
			dfs_low[i] = 0;
			is_cycle[i] = false;
		}
		dfs_count = 1;
		count = 0;
	}
}

int main()
{
	run();
	return 0;
}