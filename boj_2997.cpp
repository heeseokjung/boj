#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> v(3);
    for(int i = 0; i < 3; ++i)
        scanf("%d", &v[i]);
    sort(v.begin(), v.end());
    if(v[1] - v[0] > v[2] - v[1])
        printf("%d\n", v[1] - (v[2] - v[1]));
    else if(v[1] - v[0] < v[2] - v[1])
        printf("%d\n", v[1] + (v[1] - v[0]));
    else 
        printf("%d\n", v[2] + (v[1] - v[0]));
    return 0;
}