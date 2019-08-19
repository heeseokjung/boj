#include <stdio.h>
#include <algorithm>
using namespace std;

int N;
int num_size = 0, op_size = 0;
int num[19];
char op[19];
int ans = -1;

void input()
{
	scanf("%d", &N);
	getchar();
	char c;
	for(int i = 0; i < N; ++i) {
		scanf("%c", &c);
		if(i % 2 == 0)
			num[num_size++] = c - '0';
		else
			op[op_size++] = c;
	}
}

int calculate(int a, int b, char op)
{
	switch(op) {
		case '+':
			return a + b;
		case '-':
			return a - b;
		case '*':
			return a * b;
	}
}

void dfs(int pos, int val)
{
	if(pos >= op_size) {
		ans = max(ans, val);
		return;
	}
	int next_val;
	if(pos + 1 < op_size) {
		next_val = calculate(num[pos+1], num[pos+2], op[pos+1]);
		next_val = calculate(val, next_val, op[pos]);
		dfs(pos + 2, next_val);
	}
	next_val = calculate(val, num[pos+1], op[pos]);
	dfs(pos + 1, next_val);
}

void run()
{
	dfs(0, num[0]);
	printf("%d\n", ans);
}

int main()
{
	input();
	run();
	return 0;
}