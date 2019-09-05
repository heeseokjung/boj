#include <stdio.h>
#include <utility>
#include <algorithm>
using namespace std;

int n;
pair<int, pair<int, int> > ball[200001];
int rsum[200001] = {0, };
int crsum[200001] = {0, };
int ans[200001];

void input()
{
	scanf("%d", &n);
	int c, s;
	for(int i = 1; i <= n; ++i) {
		scanf("%d %d", &c, &s);
		ball[i] = make_pair(i, make_pair(c, s));
	}
}

bool comp(pair<int,  pair<int, int> >& p1, pair<int, pair<int, int> >& p2)
{
	return p1.second.second < p2.second.second;
}

void run()
{
	input();
	
	sort(ball + 1, ball + n + 1, comp);
	
	for(int i = 1; i <= n; ++i) {
		rsum[i] = rsum[i-1] + ball[i].second.second;
	}
	for(int i = 1, j = 1; i <= n; ++i) {
		while(j < n && ball[j].second.second < ball[i].second.second) {
			crsum[ball[j].second.first] += ball[j].second.second;
			j++;
		}
		int sum = rsum[j-1] - rsum[0];
		ans[ball[i].first] = sum - crsum[ball[i].second.first];
	}
	for(int i = 1; i <= n; ++i)
		printf("%d\n", ans[i]);
}

int main()
{
	run();
	return 0;
}