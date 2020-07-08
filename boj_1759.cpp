#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

void comb(vector<char>& v, vector<char>& s, int pos, int count, int L) {
    printf("pos: %d count: %d L: %d s.size: %d  |  ", pos, count, L, (int)s.size());
    for(int i = 0; i < (int)s.size(); ++i)
        printf("%c", s[i]);
    printf("\n");
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

    int size = (int)v.size();
    if(pos >= size)
        return;

    for(int i = pos; i < size; ++i) {
        s.push_back(v[i]);
        comb(v, s, pos+1, count+1, L);
        s.pop_back();
        comb(v, s, pos+1, count, L);
    }
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

    for(int i = 0; i < C; ++i)
        printf("%c", v[i]);
    printf("\n");

    return 0;
}