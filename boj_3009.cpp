#include <cstdio>
#include <utility>
using namespace std;

int main() {
    pair<int, int> p[3];
    for(int i = 0; i < 3; ++i) 
        scanf("%d %d", &p[i].first, &p[i].second);
    int x, y;
    for(int i = 0; i < 3; ++i) {
        int count = 0;
        for(int j = 0; j < 3; ++j) {
            if(p[i].first == p[j].first)
                count++;
        }
        if(count == 1) {
            x = p[i].first;
            break;
        }
    }
    for(int i = 0; i < 3; ++i) {
        int count = 0;
        for(int j = 0; j < 3; ++j) {
            if(p[i].second == p[j].second)
                count++;
        }
        if(count == 1) {
            y = p[i].second;
            break;
        }
    }
    printf("%d %d\n", x, y);
    return 0;
}