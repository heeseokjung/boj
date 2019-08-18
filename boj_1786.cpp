#include <iostream>
#include <string>
#include <vector>
using namespace std;

string T, P;
int N, M;
int back[1000001];
vector<int> ans;

void input()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	getline(cin, T);
	getline(cin, P);
	N = T.size();
	M = P.size();
}

void run()
{
	int i = 1, j = 0;
	while(i < M) {
		while(j > 0 && P[j] != P[i])
			j = back[j-1];
		if(P[j] == P[i])
			back[i] = ++j;
		++i;
	}
	
	i = 0, j = 0;
	while(i < N) {
		while(j > 0 && T[i] != P[j])
			j = back[j-1];
		if(T[i] == P[j]) {
			if(j == M - 1) {
				ans.push_back(i - j + 1);
				j = back[j];
			}
			else {
				++j;
			}
		}
		++i;
	}
	
	cout << ans.size() << "\n";
	for(int i = 0; i < (int)ans.size(); ++i)
		cout << ans[i] << "\n";
}

int main()
{
	input();
	run();
	return 0;
}