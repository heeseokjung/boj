#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

inline int absl(int x) {
	return x < 0 ? -x : x;
}

struct cmp {
	bool operator()(int x, int y) {
		if(absl(x) == absl(y))
			return x > y;
		else
			return absl(x) > absl(y);
	}
};

int main() {
	int N;
	scanf("%d", &N);
	priority_queue<int, vector<int>, cmp> pq;
	
	while(N--) {
		int cmd;
		scanf("%d", &cmd);
		if(cmd == 0) {
			if(pq.empty()) {
				printf("0\n");
			} else {
				printf("%d\n", pq.top());
				pq.pop();
			}
		} else {
			pq.push(cmd);
		}
	}
	
	return 0;
}