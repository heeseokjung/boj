#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
using namespace std;

int N;
const int inf = 100;
string sentence;
vector<string> v;
vector<int> cache;

int get_score(string& s, int i, int j) {
    int ret = 0, len = (int)s.size();
    vector<int> cnt1(26, 0), cnt2(26, 0);
    for(int k1 = 0, k2 = i; k1 < len && k2 <= j; ++k1, ++k2) {
        cnt1[s[k1]-'a']++; cnt2[sentence[k2]-'a']++;
        if(s[k1] != sentence[k2])
            ret++;
    }

    for(int k = 0; k < 26; ++k) {
        if(cnt1[k] != cnt2[k])
            return inf;
    }

    return ret;
}

int dp(int pos) {
    if(pos < 0)
        return 0;
    if(cache[pos] != -1)
        return cache[pos];
    int mn = inf;
    for(int i = 0; i < N; ++i) {
        string& s = v[i];
        int len = (int)s.size();
        if(pos-len+1 >= 0) {
            int score = get_score(s, pos-len+1, pos) + dp(pos-len);
            mn = (mn > score ? score : mn);  
        }
    }
    return cache[pos] = mn;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> sentence;
    cin >> N;
    v = vector<string>(N);
    for(int i = 0; i < N; ++i)
        cin >> v[i];

    cache.assign((int)sentence.size(), -1);
    int ans = dp((int)sentence.size()-1);
    if(ans < inf)
        cout << ans << "\n";
    else
        cout << "-1\n";

    return 0;
}