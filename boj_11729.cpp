// boj_11729

#include <cstdio>

using namespace std;

int num_disk;
void run(int n, int p1, int p2, int p3);

int main()
{
    scanf("%d", &num_disk);

    printf("%d\n", (1 << num_disk) - 1);
    run(num_disk, 1, 2, 3);
    
    return 0;
}

void run(int n, int p1, int p2, int p3)
{
    if(n == 1) {
        printf("%d %d\n", p1, p3);
        return;
    }

    run(n - 1, p1, p3, p2);
    printf("%d %d\n", p1, p3);
    run(n - 1, p2, p1, p3);
}