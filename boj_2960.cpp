#include <stdio.h>
using namespace std;

int N, K;
bool number[1001] = {false, };

inline bool is_prime(int x)
{
	for(int i = 2; i*i <= x; ++i) {
		if(x % i == 0)
			return false;
	}
	return true;
}

int run()
{
	scanf("%d %d", &N, &K);
	int count = 0;
	for(int i = 2; i <= N; ++i) {
		if(!number[i] && is_prime(i)) {
			for(int j = 1; i*j <= N; ++j) {
				if(!number[i*j]) {
					number[i*j] = true;
					if(++count == K)
						return i*j;
				}
			}
		}
	}
}

int main()
{
	printf("%d\n", run());
	return 0;
}