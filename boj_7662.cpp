#include <iostream>
#include <queue>
#include <map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int TC;
    cin >> TC;
    while(TC--) {
        int k;
        cin >> k;
        map<int, int> m;
        priority_queue<int> min_pq, max_pq;
        for(int i = 0; i < k; ++i) {
            int n;
            string cmd;
            cin >> cmd >> n;
            
            if(cmd == "I") {
                auto it = m.find(n);
                if(it == m.end())
                    m.insert({n, 1});
                else
                    it->second++;
                min_pq.push(-n);
                max_pq.push(n);
            } else if(cmd == "D") {
                if(m.size() == 0)
                    continue;
                if(n == 1) {
                    while(!max_pq.empty()) {
                        int x = max_pq.top();
                        max_pq.pop();
                        auto it = m.find(x);
                        if(it != m.end()) {
                            if(it->second == 1)
                                m.erase(it);
                            else
                                it->second--;
                            break;
                        }
                    }
                } else if(n == -1) {
                    while(!min_pq.empty()) {
                        int x = -min_pq.top();
                        min_pq.pop();
                        auto it = m.find(x);
                        if(it != m.end()) {
                            if(it->second == 1)
                                m.erase(it);
                            else
                                it->second--;
                            break;
                        }
                    }
                }
            }
        }

        if(m.size() == 0)
            cout << "EMPTY\n";
        else 
            cout << max_pq.top() << " " << -min_pq.top() << "\n";
    }

    return 0;
}