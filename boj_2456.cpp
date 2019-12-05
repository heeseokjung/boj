#include <cstdio>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct Student {
    int sid;
    int sum = 0;
    long long checksum = 0;

    inline void set(int x) {
        switch(x) {
            case 1:
                checksum += (long long)x;
                break;
            case 2:
                checksum += (long long)x * 1000LL;
                break;
            case 3:
                checksum += (long long)x * 1000000LL;
                break;
            default:
                break;
        }
    }
}Student;

inline bool compare(Student& s1, Student& s2) {
    if(s1.sum == s2.sum)
        return s1.checksum < s2.checksum;
    else
        return s1.sum < s2.sum;
}

int main() {
    int N;
    vector<Student> v(3);
    for(int i = 0; i < 3; ++i)
        v[i].sid = i+1;
    scanf("%d", &N);
    for(int i = 0; i < N; ++i) {
        for(int j = 0, k; j < 3; ++j) {
            scanf("%d", &k);
            v[j].sum += k;
            v[j].set(k);
        }
    }
    sort(v.begin(), v.end(), compare);
    if(v[2].sum == v[1].sum) {
        if(v[2].checksum == v[1].checksum)
            printf("0 %d\n", v[2].sum);
        else
            printf("%d %d\n", (v[1].checksum < v[2].checksum) ? v[2].sid : v[1].sid, v[2].sum);
    }
    else {
        printf("%d %d\n", v[2].sid, v[2].sum);
    }
    return 0;
}