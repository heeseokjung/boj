#include <cstdio>
#include <vector>
#include <set>
using namespace std;

int N, K;
bool power[101];
vector<int> v;

int main() {
    scanf("%d %d", &N, &K);
    v = vector<int>(K);
    for(int i = 0; i < K; ++i)
        scanf("%d", &v[i]);

    int count = 0;
    set<int> s;
    for(int i = 0; i < K; ++i) {
        if(power[v[i]])
            continue;
        if(s.size() < N) {
            s.insert(v[i]);
            power[v[i]] = true;
        } else {
            int mx = -1;
            set<int>:: iterator p;
            for(auto it = s.begin(); it != s.end(); ++it) {
                int j, pos;
                for(j = i+1; j < K; ++j) {
                    if(v[j] == *it) {
                        pos = j;
                        break;
                    }
                }
                if(j == K) {
                    pos = K;
                }
                if(mx < pos) {
                    mx = pos;
                    p = it;
                }
            }

            power[*p] = false;
            s.erase(p);
            s.insert(v[i]);
            power[v[i]] = true;
            
            count++;
        }
    }

    printf("%d\n", count);

    return 0;
}