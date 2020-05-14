#include <iostream>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

int N, H;
vector<int> adj[20];
int visit[1050000];
long long sum[1050000];
int fan_out[20];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> H;
    for(int i = 0; i < N; ++i) {
        string s;
        cin >> s;
        for(int j = 0; j < N; ++j) {
            if(s[j] == '1')
                adj[i].push_back(j);
        }
        fan_out[i] = (int)adj[i].size();
    }

    memset(visit, -1, sizeof(visit));

    int state = 0;
    for(int i = 0; i < (int)adj[0].size(); ++i)
        state |= (1<<adj[0][i]);
    visit[state] = 1;
    sum[1] = fan_out[0];
    
    long long ans = sum[1];
    for(int i = 2; i <= H; ++i) {
        visit[state] = i;
        int next_state = 0, count = 0;
        for(int j = 0; j < N; ++j) {
            if(state & (1<<j)) {
                for(int k = 0; k < (int)adj[j].size(); ++k)
                    next_state ^= (1<<adj[j][k]);
                count += fan_out[j];
            } else {
                count += 2*fan_out[j];
            }
        }

        ans += (long long)count;
        sum[i] = sum[i-1] + (long long)count;

        if(visit[next_state] != -1) {
            int s = visit[next_state], e = i;
            int rep = (H - i)/(e - s + 1);
            int remain = (H - i)%(e - s + 1);
            ans += (long long)rep * (sum[e] - sum[s-1]);
            ans += (sum[s+remain-1] - sum[s-1]);
            break;  
        } else {
            state = next_state;
        }
    }

    cout << ans << "\n";

    return 0;
}