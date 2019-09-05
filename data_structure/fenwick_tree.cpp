// Implements Fenwick Tree API
#include <vector>
using namespace std;

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
	void update(T i, T val);
};

template <typename T>
FenwickTree<T>::FenwickTree(T size)
{
	tree = vector<T>(size + 1);
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
	if(i == 1)
		return partial_sum(j);
	else
		return partial_sum(j) - partial_sum(i - 1);
}

template <typename T>
void FenwickTree<T>::update(T i, T val)
{
	while(i <= size) {
		tree[i] += val;
		i += (i & -i);
	}
}









