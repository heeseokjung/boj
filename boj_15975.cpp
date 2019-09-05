#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int n;
long long total_length = 0;
vector<long long> color[100001];

void run();

int main()
{
	scanf("%d", &n);
	int x, y;
	for(int i = 0; i < n; ++i) {
		scanf("%d %d", &x, &y);
		color[y].push_back(x);
	}
	
	run();
	
	return 0;
}

void run()
{
	for(int i = 1; i <= n; ++i) {
		if(color[i].size() > 1) {
			sort(color[i].begin(), color[i].end());
			int size = (int)color[i].size();
			for(int j = 0; j < size; ++j) {
				if(j == 0) {
					total_length += color[i][j+1] - color[i][j];
				}
				else if(j == size - 1) {
					total_length += color[i][j] - color[i][j-1];
				}
				else {
					if(color[i][j] - color[i][j-1] < color[i][j+1] - color[i][j])
						total_length += color[i][j] - color[i][j-1];
					else
						total_length += color[i][j+1] - color[i][j];
				}
			}
		}
	}
	
	printf("%lld\n", total_length);
}