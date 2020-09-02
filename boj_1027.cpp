#include <cstdio>
#include <vector>
using namespace std;

int main() {
    int N;
    scanf("%d", &N);
    vector<int> v(N);
    for(int i = 0; i < N; ++i)
        scanf("%d", &v[i]);

    int mx = 0;
    for(int i = 0; i < N; ++i) {
        int count = 0;
        for(int j = 0; j < N; ++j) {
            if(i == j)
                continue;
            bool imp = false;
            double tan1 = (double)(v[i]-v[j]) / (double)(i-j);
            for(int k = i+1; k < j; ++k) {
                double tan2 = (double)(v[i]-v[k]) / (double)(i-k);
                if(tan2 >= tan1) {
                    imp = true;
                    break;
                }
            }
            for(int k = j+1; k < i; ++k) {
                double tan2 = (double)(v[i]-v[k]) / (double)(i-k);
                if(tan2 <= tan1) {
                    imp = true;
                    break;
                }
            }
            if(!imp)
                count++;
        }
        mx = (mx < count ? count : mx);
    }

    printf("%d\n", mx);
    
    return 0;
}