#include <cstdio>

int main() {
    int arr[10];
    bool remainder[42];
    for(int i = 0; i < 42; ++i)
        remainder[i] = false;
    for(int i = 0; i < 10; ++i)
        scanf("%d", arr+i);
    for(int i = 0; i < 10; ++i)
        remainder[arr[i] % 42] = true;
    int count = 0;
    for(int i = 0; i < 42; ++i) {
        if(remainder[i])
            count++;
    }
    printf("%d\n", count);
    return 0;
}