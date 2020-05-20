#include <cstdio>
#include <cstring>

int len;
char s[110];
int type[110];
#define UNDER_BAR 0
#define VOWEL 1
#define L 2
#define CONSONANT 3

long long run(int pos, bool isL) {
    long long ret = 0LL;
    for(int i = pos; i < len; ++i) {
        if(type[i] == UNDER_BAR) {
            type[i] = VOWEL;
            ret += 5LL * run(i, isL);
            type[i] = L;
            ret += run(i, true);
            type[i] = CONSONANT;
            ret += 20LL * run(i, isL);
            type[i] = UNDER_BAR;
            return ret;
        } else {
            if(type[i] == L)
                isL = true;
            if(i >= 2) {
                if(type[i] == VOWEL && type[i-1] == VOWEL && type[i-2] == VOWEL)
                    return 0LL;
                if(type[i] != VOWEL && type[i-1] != VOWEL && type[i-2] != VOWEL)
                    return 0LL;
            }
        }
    }
    return isL ? 1LL : 0LL;
}

int main() {
    scanf("%s", s);

    len = strlen(s);
    for(int i = 0; i < len; ++i) {
        if(s[i] == '_')
            type[i] = UNDER_BAR; 
        else if(s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
            type[i] = VOWEL;
        else if(s[i] == 'L')
            type[i] = L;
        else
            type[i] = CONSONANT;
    }

    printf("%lld\n", run(0, false));

    return 0;
}