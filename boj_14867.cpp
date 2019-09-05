#include <stdio.h>
#include <utility>
#include <queue>
#include <set>

using namespace std;

int a, b, c, d;
typedef pair<int, int> ii;
queue<pair<ii, int> > q;
set<int> visit[100001];

pair<int, int> a_to_b(int x, int y)
{
	if(x <= b - y) {
		y += x;
		x = 0;
	}
	else {
		x -= (b - y);
		y = b;
	}
	
	return make_pair(x, y);
}

pair<int, int> b_to_a(int x, int y)
{
	if(y <= a - x) {
		x += y;
		y = 0;
	}
	else {
		y -= (a - x);
		x = a;
	}

	return make_pair(x, y);
}

void next(int x, int y, int count)
{
	if(x < a && visit[a].find(y) == visit[a].end()) {                       // F(x)
		visit[a].insert(y);
		q.push(make_pair(make_pair(a, y), count + 1));  
	} 
	if(y < b && visit[x].find(b) == visit[x].end()) {                       // F(y)
		visit[x].insert(b);
		q.push(make_pair(make_pair(x, b), count + 1));
	}
	if(x != 0 && visit[0].find(y) == visit[0].end()) {                      // E(x)
		visit[0].insert(y);
		q.push(make_pair(make_pair(0, y), count + 1));
	}
	if(y != 0 && visit[x].find(0) == visit[x].end()) {                      // E(y)
		visit[x].insert(0);
		q.push(make_pair(make_pair(x, 0), count + 1));
	}
	pair<int, int> m = a_to_b(x, y);
	if(x != 0 && visit[m.first].find(m.second) == visit[m.first].end()) {   // M(x, y)
		visit[m.first].insert(m.second);
		q.push(make_pair(m, count + 1));
	}
	pair<int, int> n = b_to_a(x, y);
	if(y != 0 && visit[n.first].find(n.second) == visit[n.first].end()) {  // M(y, x)
		visit[n.first].insert(n.second);
		q.push(make_pair(n, count + 1));
	}
}

int run()
{
	visit[0].insert(0);
	q.push(make_pair(make_pair(0, 0), 0));
	
	while(!q.empty()) {
		pair<ii, int> p = q.front();
		q.pop();
		if(p.first.first == c && p.first.second == d)
			return p.second;
		next(p.first.first, p.first.second, p.second);
	}
	
	return -1;
}

int main()
{
	scanf("%d %d %d %d", &a, &b, &c, &d);
	
	int ans = run();
	printf("%d\n", ans);
	
	return 0;
}