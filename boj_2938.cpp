#include <cstdio>
#include <vector>
using namespace std;

int main() {
    int N;
    scanf("%d", &N);

    vector<int> v0, v1, v2;
    for(int i = 0, j; i < N; ++i) {
        scanf("%d", &j);
        switch(j % 3) {
            case 0:
                v0.push_back(j);
                break;
            case 1:
                v1.push_back(j);
                break;
            case 2:
                v2.push_back(j);
                break;
        }
    }

    int v0_size = (int)v0.size();
    int v1_size = (int)v1.size();
    int v2_size = (int)v2.size();

    if(v0_size == 0 && v1_size != 0 && v2_size != 0) {
        printf("-1\n");
    } else if(v0_size > (v1_size + v2_size + 1)) {
        printf("-1\n");
    } else {
        int i = 0, j = 0, k = 0;
        while(i < v0_size-1 && j < v1_size) {
            printf("%d ", v0[i++]);
            printf("%d ", v1[j++]);
        }
        while(j < v1_size) {
            printf("%d ", v1[j++]);
        }
        if(i < v0_size)
            printf("%d ", v0[i++]);
        while(i < v0_size || k < v2_size) {
            if(k < v2_size)
                printf("%d ", v2[k++]);
            if(i < v0_size)
                printf("%d ", v0[i++]);
        }
        printf("\n");
    }

    return 0;
}