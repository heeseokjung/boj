#include <stdio.h>
using namespace std;

int N, M;

int get_gcd(int a, int b)
{
	if(a < b) {
		int tmp = a;
		a = b;
		b = tmp;
	}
	while(a % b) {
		int tmp = a;
		a = b;
		b = tmp % b;
	}
	return b;
}

void run()
{
	scanf("%d %d", &N, &M);
	int gcd = get_gcd(N, M);
	printf("%d\n%d\n", gcd, N*M/gcd);
}

int main()
{
	run();
	return 0;
}