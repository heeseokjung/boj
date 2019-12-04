#include <cstdio>

int M, N;
bool check[1000001];

int main() {
	scanf("%d %d", &M, &N);
	check[1] = true;
	for(int i = 2; i <= N; ++i) {
		if(!check[i]) {
			for(int j = 2; i*j <= N; ++j)
				check[i*j] = true;
		}
	}
	for(int i = M; i <= N; ++i) {
		if(!check[i])
			printf("%d\n", i);
	}
	return 0;
}