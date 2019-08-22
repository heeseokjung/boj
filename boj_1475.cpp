#include <stdio.h>
#include <algorithm>
using namespace std;

int N;
int num[10];
int ans;

void run()
{
	scanf("%d", &N);
	int p = N;
	if(p == 0)
		num[0]++;
	while(p) {
		num[p%10]++;
		p /= 10;
	}
	int max_num = 0;
	for(int i = 0; i < 10; ++i) {
		if(i == 6 || i == 9)
			continue;
		max_num = max(max_num, num[i]);
	}
	ans = max_num;
	ans = max(ans, (num[6] + num[9])/2 + (num[6] + num[9])%2);
	printf("%d\n", ans);
}

int main()
{
	run();
	return 0;
}