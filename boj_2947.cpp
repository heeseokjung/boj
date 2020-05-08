#include <cstdio>
#include <vector>
using namespace std;

inline void swap(int& x, int& y) {
    int tmp = x;
    x = y;
    y = tmp;
}

void printAll(vector<int>& v) {
    for(int i = 0; i < 5; ++i)
        printf("%d ", v[i]);
    printf("\n");
}

int main() {
    vector<int> v(5);
    for(int i = 0; i < 5; ++i)
        scanf("%d", &v[i]);

    while(true) {
        for(int i = 0; i < 4; ++i) {
            if(v[i] > v[i+1]) {
                swap(v[i], v[i+1]);
                printAll(v);
            }
        }

        bool sorted = true;
        for(int i = 0; i < 4; ++i) {
            if(v[i] > v[i+1]) {
                sorted = false;
                break;
            }
        }

        if(sorted)
            break;
    }
    
    return 0;
}