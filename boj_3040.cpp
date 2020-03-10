#include <cstdio>
#include <utility>
#include <vector>
using namespace std;

pair<int, int> find(vector<int>& v, int sum) {
    for(int i = 0; i < 8; ++i) {
        for(int j = i+1; j < 9; ++j) {
            if(sum - v[i] - v[j] == 100)
                return pair<int, int>(i, j);
        }
    }
}

int main() {
    vector<int> v(9);
    for(int i = 0; i < 9; ++i)
        scanf("%d", &v[i]);
    int sum = 0;
    for(int i = 0; i < 9; ++i)
        sum += v[i];
    pair<int, int> p = find(v, sum);
    for(int i = 0; i < 9; ++i) {
        if(i == p.first || i == p.second)
            continue;
        printf("%d\n", v[i]);
    }
    return 0;
}