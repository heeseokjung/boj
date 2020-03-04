#include <cstdio>
#include <iostream>
using namespace std;

const char* peter[5] = {"..#.",
                        ".#.#",
                        "%c.%c.",
                        ".#.#",
                        "..#.",};
const char* wendy[5] = {"..*.",
                        ".*.*",
                        "%c.%c.",
                        ".*.*",
                        "..*.",};

int main() {
    string s;
    cin >> s;
    int size = (int)s.size();
    for(int i = 0; i < 5; ++i) {
        for(int j = 0; j < size; ++j) {
            if((j + 1) % 3 == 0) {
                if(i == 2) {
                    printf(wendy[i], '*', s[j]);
                } else {
                    printf(wendy[i]);
                }
                if(j == size-1)
                    printf("%c", i == 2 ? '*' : '.');
            } else {
                if(i == 2) {
                    printf(peter[i], (j > 0 && j % 3 == 0) ? '*' : '#', s[j]);
                } else {
                    printf(peter[i]);
                }
                if(j == size-1)
                    printf("%c", i == 2 ? '#' : '.');
            }
        }
        printf("\n");
    }
    return 0;
}