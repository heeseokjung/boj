#include <iostream>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

int N, H;
vector<int> adj[20];
int visit[1050000];
int count[1050000];
int num[20];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> H;
    for(int i = 0; i < N; ++i) {
        string s;
        cin >> s;
        for(int j = 0; j < (int)s.size(); ++j) {
            if(s[j] == '1')
                adj[i].push_back(j);
        }
    }

    memset(visit, -1, sizeof(visit));

    long long sum = 0;
    int state = 1, step = 0;
    visit[state] = step++;
    num[0] = 1;
    vector<int> cycle;
    while(H) {
        int cnt = 0;
        int next[20];
        for(int i = 0; i < N; ++i)
            next[i] = 0;
        for(int i = 0; i < N; ++i) {
            if(num[i] % 2) {
                cnt += (int)adj[i].size();
                for(int j = 0; j < (int)adj[i].size(); ++j)
                    next[adj[i][j]]++;
            } else {
                cnt += (int)adj[i].size() * 2;
                for(int j = 0; j < (int)adj[i].size(); ++j)
                    next[adj[i][j]] += 2;
            }
        }
        count[step] = cnt;
        --H;

        int next_state = 0;
        for(int i = 0; i < N; ++i) {
            num[i] = next[i];
            if(num[i] % 2)
                next_state |= (1 << i);
        }

        if(visit[next_state] != -1) {
            for(int i = visit[next_state]; i <= visit[state]; ++i)
                cycle.push_back(count[i]);
            break;
        } else {
            visit[next_state] = ++step;
            state = next_state;
        }
    }

    if(H) {
        int cycle_size = (int)cycle.size();
        int cycle_sum = 0;
        for(int i = 0; i < cycle_size; ++i)
            cycle_sum += cycle[i];
        sum += (long long)cycle_sum * (long long)(H / cycle_size);
        for(int i = 0; i < (H % cycle_size); ++i)
            sum += (long long)cycle[i];
        cout << sum << "\n";
    } else {
        cout << sum << "\n";
    }

    return 0;
}