#include <bits/stdc++.h>

using namespace std;

int m, n;
vector<int> matrix[200000];
int dp[200000];

void run();
bool comp(vector<int>& v1, vector<int>& v2);
void search(int p, int r, vector<map<int, int> >& lis, pair<int, int> x);

int main()
{
	scanf("%d %d", &m, &n);
	int num;
	for(int i = 0; i < m; ++i) {
		for(int j = 0; j < n; ++j) {
			scanf("%d", &num);
			matrix[j].push_back(num);
		}
	}
	
	run();
	
	return 0;
}

void run()
{
	sort(matrix, matrix + n, comp);
	
	int lis_size, pivot = 0;
	if(m == 2) {
		vector<int> lis;
		lis.push_back(matrix[0][1]);
		for(int i = 0; i < n; ++i) {
			if(lis[pivot] < matrix[i][1]) {
				lis.push_back(matrix[i][1]);
				pivot++;
			}
			else {
				int idx = lower_bound(lis.begin(), lis.end(), matrix[i][1]) - lis.begin();
				lis[idx] = matrix[i][1];
			}
		}
		lis_size = (int)lis.size();
	} 
	else if(m == 3) {
		vector<map<int, int> > lis;
		lis.reserve(n);
		for(int i = 0; i < n; ++i) {
			pair<int, int> p = make_pair(matrix[i][1], matrix[i][2]);
			if(lis.empty()) {
				map<int, int> m;
				m.insert(p);
				lis.push_back(m);
			}
			else {
				search(0, (int)lis.size() - 1, lis, p);
			}
		}
		lis_size = (int)lis.size();
	}
	
	printf("%d\n", lis_size);
}

bool comp(vector<int>& v1, vector<int>& v2)
{
	return v1[0] < v2[0];
}

void search(int p, int r, vector<map<int, int> >& lis, pair<int, int> x)
{
    int q;
	while(p <= r) {
        q = (p + r) / 2;
		auto it = lis[q].lower_bound(x.first);
        if(it != lis[q].begin() && (--it)->second < x.second)
            p = q + 1;
        else
            r = q - 1;
    }

    for(auto it = lis[p].lower_bound(x.first); it != lis[p].end() && it->second > x.second; )
        it = lis[p].erase(it);
		
    if(p >= (int)lis.size()) {
		map<int, int> m;
		m.insert(x);
		lis.push_back(m);
	}
	else {
		lis[p].insert(x);
	}
}