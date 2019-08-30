#include <stdio.h>

#define MAX 246912
bool is_prime[246913];
int rsum[246913];

void run()
{
	for(int i = 1; i <= MAX; ++i)
		is_prime[i] = true;
	for(int i = 2; i <= MAX; ++i) {
		if(!is_prime[i]) {
			continue;
		}
		else {
			for(int j = i + i; j <= MAX; j += i)
				is_prime[j] = false;
		}
	}
	for(int i = 2; i <= MAX; ++i) {
		if(is_prime[i])
			rsum[i] = rsum[i-1] + 1;
		else
			rsum[i] = rsum[i-1];
	}
	
	int n;
	while(true) {
		scanf("%d", &n);
		if(!n)
			break;
		printf("%d\n", rsum[n*2] - rsum[n]);
	}
}

int main()
{
	run();
	return 0;
}