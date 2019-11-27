#include <cstdio>
#include <utility>
using namespace std;

pair<int, int> convert1(int x) {
    int i, j;
    for(i = 1, j = 0; i + j <= x; ++j)
        i += j;
    pair<int, int> p = pair<int, int>(1, j);
    for(; i < x; ++i) {
        p.first++;
        p.second--;
    }
    return p;
}

int convert2(pair<int, int>& p) {
    int i = p.first + p.second - 1;
    int j = i*(i-1)/2 + 1;
    pair<int, int> q = pair<int, int>(1, p.first + p.second - 1);
    while(q != p) {
        q.first++;
        q.second--;
        j++;
    }
    return j;
}

int main() {
    int TC;
    scanf("%d", &TC);
    while(TC--) {
        int m, n;
        scanf("%d %d", &m, &n);
        pair<int, int> p1, p2;
        p1 = convert1(m);
        p2 = convert1(n);
        pair<int, int> p3 = pair<int, int>(p1.first + p2.first, p1.second + p2.second);
        printf("%d\n", convert2(p3));
    }
    return 0;
}