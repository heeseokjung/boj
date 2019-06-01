#include <stdio.h>
#include <vector>

using namespace std;

int n, m, k;
long long arr[1000001];
vector<long long> ans;

template <typename T>
class FenwickTree
{
private:
	vector<T> tree;
	T size;
public:
	FenwickTree(T size);
	T partial_sum(T n);
	T query(T i, T j);
	void update(T i, T diff);
};

template <typename T>
FenwickTree<T>::FenwickTree(T size)
{
	tree = vector<T>(size + 1);
	this->size = size;
}

template <typename T>
T FenwickTree<T>::partial_sum(T n)
{
	T sum = 0;
	while(n > 0) {
		sum += tree[n];
		n -= (n & -n);
	}
	return sum;
}

template <typename T>
T FenwickTree<T>::query(T i, T j)
{
	return partial_sum(j) - partial_sum(i - 1);
}

template <typename T>
void FenwickTree<T>::update(T i, T diff)
{
	while(i <= size) {
		tree[i] += diff;
		i += (i & -i);
	}
}

int main()
{
	scanf("%d %d %d", &n, &m, &k);
	for(int i = 1; i <= n; ++i)
		scanf("%lld", &arr[i]);
	
	FenwickTree<long long> ft(n);
	for(int i = 1; i <= n; ++i)
		ft.update(i, arr[i]);
	
	long long a, b, c;
	for(int i = 0; i < m + k; ++i) {
		scanf("%lld %lld %lld", &a, &b, &c);
		if(a == 1) {
			ft.update(b, c - arr[b]);
			arr[b] = c;
		}
		else if(a == 2) {
			ans.push_back(ft.query(b, c));
		}
	}
	
	for(int i = 0; i < k; ++i)
		printf("%lld\n", ans[i]);
	
	return 0;
}