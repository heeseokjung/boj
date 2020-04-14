#include <cstdio>
#include <utility>
using namespace std;

int N, L;
pair<int, int> road[1001];

int main() {
    scanf("%d %d", &N, &L);
    for(int i = 0; i <= L; ++i)
        road[i].first = road[i].second = 0;
    for(int i = 0; i < N; ++i) {
        int pos;
        scanf("%d", &pos);
        scanf("%d %d", &road[pos].first, &road[pos].second);
    }

    int time = 0;
    for(int i = 1; i <= L; ++i) {
        time++;
        if(road[i].first == 0 && road[i].second == 0)
            continue;
    }

    return 0;
}