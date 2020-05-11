#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;
    vector<string> v(N);
    for(int i = 0; i < N; ++i)
        cin >> v[i];

    vector<int> count[50];
    for(int i = 0; i < M; ++i)
        count[i] = vector<int>(4, 0);

    for(int j = 0; j < M; ++j) {
        for(int i = 0; i < N; ++i) {
            switch(v[i][j]) {
                case 'A':
                    count[j][0]++;
                    break;
                case 'C':
                    count[j][1]++;
                    break;
                case 'G':
                    count[j][2]++;
                    break;
                case 'T':
                    count[j][3]++;
                    break;
                default:
                    break;
            }
        }
    }

    string ans;
    for(int i = 0; i < M; ++i) {
        auto it = max_element(count[i].begin(), count[i].end());
        if(it == count[i].begin())
            ans += 'A';
        else if(it == (count[i].begin() + 1))
            ans += 'C';
        else if(it == (count[i].begin() + 2))
            ans += 'G';
        else if(it == (count[i].begin() + 3))
            ans += 'T';
    }   
    cout << ans << "\n";

    int sum = 0;
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < M; ++j) {
            if(v[i][j] != ans[j])
                sum++;
        }
    }
    cout << sum << "\n";

    return 0;
}