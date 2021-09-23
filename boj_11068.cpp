#include <cstdio>
#include <vector>
using namespace std;

bool is_palindrome(vector<int>& v) {
    for(int i = 0, j = (int)v.size()-1; i < j; ++i, --j) {
        if(v[i] != v[j])
            return false;
    }
    return true;
}

int main() {
    int TC;
    scanf("%d", &TC);
    while(TC--) {
        int N;
        scanf("%d", &N);

        bool check;
        for(int basis = 2; basis <= 64; ++basis) {
            int num = N;
            vector<int> v;
            while(num > 0) {
                v.push_back(num % basis);
                num /= basis;
            }

            if(check = is_palindrome(v))
                break;
        }

        printf("%d\n", check ? 1 : 0);
    }

    return 0;
}