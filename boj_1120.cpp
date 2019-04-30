// boj_1120

#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s1, s2;
    s1.reserve(51); s2. reserve(51);
    cin >> s1 >> s2;

    int min_diff = 100;
    int length_diff = s2.length() - s1.length();
    for(int i = 0; i <= length_diff; ++i) {
        int diff = 0;
        for(int j = 0; j < s1.length(); ++j) {
            if(s1[j] != s2[j + i])
                diff++;
        }
        if(diff < min_diff)
            min_diff = diff;
    }

    printf("%d\n", min_diff);

    return 0;
}