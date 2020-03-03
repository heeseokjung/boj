#include <cstdio>
#include <vector>
using namespace std;

void combination(vector<int>& v, vector<int>& s, int pos) {
    if(pos > v.size())
        return;
    if((int)s.size() == 6) {
        for(int i = 0; i < 6; ++i)
            printf("%d ", s[i]);
        printf("\n");
        return;
    }
    s.push_back(v[pos]);
    combination(v, s, pos+1);
    s.pop_back();
    combination(v, s, pos+1);
}

int main() {
    int k;
    while(true) {
        scanf("%d", &k);
        if(k == 0)
            break;
        vector<int> v(k);
        for(int i = 0; i < k; ++i)
            scanf("%d", &v[i]);
        vector<int> s;
        combination(v, s, 0);
        printf("\n");
    }
    return 0;
}