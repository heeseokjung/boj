/* 
 * Implements Segment Tree API
 * If segment tree for range min query, type == true
 * If segment tree for range sum query, type == false
 */

#include <vector>
#include <cmath>
using namespace std;

#define INF 1000000000

template <typename T>
class SegmentTree
{
private:
    vector<T> tree;
public:
    SegmentTree(T* arr, int i, int j, bool type);
    T init_tree_min(T* arr, int i, int n, int j);
    T init_tree_sum(T* arr, int i, int n, int j);
    T min_query(int n, int i, int j, int l, int r);
    T sum_query(int n, int i, int j, int l, int r);
    T update_min(int n, int i, int j, int idx, int val);
    void update_sum(int n, int i, int j, int idx, int diff);
};

template <typename T>
SegmentTree<T>::SegmentTree(T* arr, int i, int j, bool type)
{
    int h = (int)ceil(log2(n));
    int tree_size = (1 << (h+1));
    tree = vector<T>(tree_size);

    if(type)
        init_tree_min(arr, i, 1, j);
    else
        init_tree_sum(arr, i, 1, j);
}

template <typename T>
T SegmentTree<T>::init_tree_min(T* arr, int i, int n, int j)
{
    if(i == j)
        return tree[n] = arr[i];
    T lmin = init_tree_min(arr, i, n*2, (i + j)/2);
    T rmin = init_tree_min(arr, (i + j)/2 + 1, n*2 + 1, j);
    return tree[n] = (lmin < rmin) ? lmin : rmin;
}

template <typename T>
T SegmentTree<T>::init_tree_sum(T* arr, int i, int n, int j)
{
    if(i == j)
        return tree[n] = arr[i];
    else
        return tree[n] = init_tree_sum(arr, i, n*2, (i + j)/2) + init_tree_sum(arr, (i + j)/2 + 1, n*2 + 1, j);
}

template <typename T>
T SegmentTree<T>::min_query(int n, int i, int j, int l, int r)
{
    if(i > r || j < l)
        return INF;
    if(l <= i && j <= r)
        return tree[n];
    T lmin = min_query(n*2, i, (i + j)/2, l, r);
    T rmin = min_query(n*2 + 1, (i + j)/2 + 1, j, l, r);
    return (lmin < rmin) ? lmin : rmin;
}

template <typename T>
T SegmentTree<T>::sum_query(int n, int i, int j, int l, int r)
{
    if(i > r || j < l)
        return 0;
    if(l <= i && j <= r)
        return tree[n];
    return sum_query(n*2, i, (i + j)/2, l, r) + sum_query(n*2 + 1, (i + j)/2 + 1, l, r);
}

template <typename T>
T SegmentTree<T>::update_min(int n, int i, int j, int idx, int val)
{
    if(idx < i || idx > j)
        return tree[n];
    if(n == idx)    
        return tree[n] = val;
    T lmin = update_min(n*2, i, (i + j)/2, idx, val);
    T rmin = update_min(n*2 + 1, (i + j)/2 + 1, idx, val);
    return tree[n] = (lmin < rmin) ? lmin : rmin;
}

template <typename T>
void SegmentTree<T>::update_sum(int n, int i, int j, int idx, int diff)
{   
    if(idx < i || idx > j)
        return;
    tree[n] += diff;
    if(i != j) {
        update_sum(n*2, i, (i + j) / 2, idx, diff);
        update_sum(n*2 + 1, (i + j)/2 + 1, j, idx, diff);
    }
}