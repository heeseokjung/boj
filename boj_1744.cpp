#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    scanf("%d", &N);
    vector<int> v(N);
    for(int i = 0; i < N; ++i)
        scanf("%d", &v[i]);

    int zero = 0;
    vector<int> pos, neg;
    for(int i = 0; i < N; ++i) {
        if(v[i] > 0)
            pos.push_back(v[i]);
        else if(v[i] < 0)
            neg.push_back(v[i]);
        else
            zero++;
    }

    sort(pos.begin(), pos.end());
    sort(neg.begin(), neg.end());

    int sum = 0, i;
    for(i = (int)pos.size()-1; i > 0; i -= 2) {
        if(pos[i] > 1 && pos[i-1] > 1)
            sum += pos[i]*pos[i-1];
        else
            break;
    }
    for( ; i >= 0; --i) {
        sum += pos[i];
    }

    for(i = 0; i < (int)neg.size()-1; i += 2) {
        sum += neg[i]*neg[i+1];
    }
    for( ; i < (int)neg.size(); ++i) {
        if(zero > 0)
            zero--;
        else
            sum += neg[i];
    }

    printf("%d\n", sum);

    return 0;
}