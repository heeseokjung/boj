#include <cstdio>

int main() {
    int start[3];
    scanf("%d:%d:%d", &start[0], &start[1], &start[2]);
    int end[3];
    scanf("%d:%d:%d", &end[0], &end[1], &end[2]);
    int borrow[3] = {24, 60, 60};
    int answer[3];
    bool check = false;
    if(start[0] == end[0] && start[1] == end[1] && start[2] == end[2]) {
        printf("24:00:00\n");
    } else {
        for(int i = 2; i >= 0; --i) {
            if(check) {
                if(end[i] - 1 - start[i] >= 0) {
                    answer[i] = end[i] - 1 - start[i];
                    check = false;
                } else {
                    answer[i] = borrow[i] + end[i] - 1 - start[i];
                    check = true;
                }
            } else {
                if(end[i] - start[i] >= 0) {
                    answer[i] = end[i] - start[i];
                    check = false;
                } else {
                    answer[i] = borrow[i] + end[i] - start[i];
                    check = true;
                }
            }
        }
        printf("%02d:%02d:%02d\n", answer[0], answer[1], answer[2]);
    }
    return 0;
}