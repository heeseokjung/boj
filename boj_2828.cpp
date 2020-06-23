#include <cstdio>

int main() {
    int N, M, K;
    scanf("%d %d %d", &N, &M, &K);
    int pos, count = 0, s = 1, e = M;
    for(int i = 0; i < K; ++i) {
        scanf("%d", &pos);
        if(s <= pos && e >= pos) {
            continue;
        } else if(s > pos) {
            int diff = s - pos;
            count += diff;
            s -= diff;
            e -= diff;
        } else if(e < pos) {
            int diff = pos - e;
            count += diff;
            s += diff;
            e += diff;
        }
    }

    printf("%d\n", count);

    return 0;
}