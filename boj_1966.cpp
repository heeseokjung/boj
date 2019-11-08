#include <cstdio>
#include <utility>
#include <vector>
using namespace std;

int main() {
    int TC, N, M;
    int doc[100];
    scanf("%d", &TC);
    while(TC--) {
        scanf("%d %d", &N, &M);
        for(int i = 0; i < N; ++i)
            scanf("%d", doc+i);
        vector<pair<int, int> > q;
        for(int i = 0; i < N; ++i)
            q.push_back(pair<int, int>(doc[i], i));
        int i = 0, count = 0;
        while(count < N) {
            bool check = false;
            for(int j = i+1; j < (int)q.size(); ++j) {
                if(q[j].first > q[i].first) {
                    check = true;
                    break;
                }
            }
            if(check) {
                q.push_back(q[i++]);
            }
            else {
                count++;
                if(q[i++].second == M)
                    printf("%d\n", count);
            }
        }
    }
}