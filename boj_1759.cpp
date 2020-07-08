#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

void comb(vector<char>& v, vector<char>& s, int pos, int count, int L) {
    if(count == L) {
        int cons = 0, vow = 0;
        for(int i = 0; i < L; ++i) {
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
                vow++;
            else
                cons++;
        }    
        if(vow >= 1 && cons >= 2) {
            for(int i = 0; i < L; ++i)
                printf("%c", s[i]);
            printf("\n");
        }
        return;
    }

    if(pos >= (int)v.size())
        return;
        
    s.push_back(v[pos]);
    comb(v, s, pos+1, count+1, L);
    s.pop_back();
    comb(v, s, pos+1, count, L);
}

int main() {
    int L, C;
    scanf("%d %d", &L, &C);
    getchar();
    vector<char> v(C);
    for(int i = 0; i < C; ++i) {
        scanf("%c", &v[i]);
        getchar();
    }

    sort(v.begin(), v.end()); 

    vector<char> s;
    comb(v, s, 0, 0, L);

    return 0;
}