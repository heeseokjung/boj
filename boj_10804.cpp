#include <stdio.h>

int arr[21];

void reverse(int s, int e)
{
	int tmp;
	for(int i = s, j = e; i < j; ++i, --j) {
		tmp = arr[i];
		arr[i] = arr[j];
		arr[j] = tmp;
	}
}

void run()
{
	for(int i = 1; i <= 20; ++i)
		arr[i] = i;
	int x, y;
	for(int i = 0; i < 10; ++i) {
		scanf("%d %d", &x, &y);
		reverse(x, y);
	}
	for(int i = 1; i <= 20; ++i) 
		printf("%d ", arr[i]);
	printf("\n");
}

int main()
{
	run();
	return 0;
}