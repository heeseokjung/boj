#include <stdio.h>

int n;
int arr[20][20];
int max_block = -1;
void (*move[4])(int(*)[20]);

void input()
{
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            scanf("%d", &arr[i][j]);
        }
    }
}

inline void swap(int& a, int& b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

void push_up(int (*copy)[20])
{
    for(int i = 0; i < n; ++i) {
        int p = 0, q = 0;
        while(p < n && !copy[p][i])
                p++;
        q = p + 1;
        while(q < n && !copy[q][i])
            q++;
        if(p < n) {
            swap(copy[0][i], copy[p][i]);
            p = 0;
        }
        bool check = false;
        while(q < n) {
            if(copy[p][i] == copy[q][i] && !check) {
                copy[p][i] = copy[p][i] * 2;
                copy[q][i] = 0;
                check = true;
            }
            else {
                copy[++p][i] = copy[q][i];
                if(p != q)
                    copy[q][i] = 0;
                check = false;
            }
            q++;
            while(q < n && !copy[q][i])
                q++;
        }
    }
}

void push_down(int (*copy)[20])
{
    for(int i = 0; i < n; ++i) {
        int p = n - 1 , q = n - 1;
        while(p >= 0 && !copy[p][i])
            p--;
        q = p - 1;
        while(q >= 0 && !copy[q][i])
            q--;
        if(p >= 0) {
            swap(copy[n-1][i], copy[p][i]);
            p = n -1;
        }
        bool check = false;
        while(q >= 0) {
            if(copy[p][i] == copy[q][i] && !check) {
                copy[p][i] = copy[p][i] * 2;
                copy[q][i] = 0;
                check = true;
            }
            else {
                copy[--p][i] = copy[q][i];
                if(p != q)
                    copy[q][i] = 0;
                check = false;
            }
            q--;
            while(q >= 0 && !copy[q][i])
                q--;
        }
    }
}

void push_left(int (*copy)[20])
{
    for(int i = 0; i < n; ++i) {
        int p = 0, q = 0;
        while(p < n && !copy[i][p])
                p++;
        q = p + 1;
        while(q < n && !copy[i][q])
            q++;
        if(p < n) {
            swap(copy[i][0], copy[i][p]);
            p = 0;
        }
        bool check = false;
        while(q < n) {
            if(copy[i][p] == copy[i][q] && !check) {
                copy[i][p] = copy[i][p] * 2;
                copy[i][q] = 0;
                check = true;
            }
            else {
                copy[i][++p] = copy[i][q];
                if(p != q)
                    copy[i][q] = 0;
                check = false;
            }
            q++;
            while(q < n && !copy[i][q])
                q++;
        }
    }
}

void push_right(int (*copy)[20])
{
    for(int i = 0; i < n; ++i) {
        int p = n - 1 , q = n - 1;
        while(p >= 0 && !copy[i][p])
                p--;
        q = p - 1;
        while(q >= 0 && !copy[i][q])
            q--;
        if(p >= 0) {
            swap(copy[i][n-1], copy[i][p]);
            p = n -1;
        }
        bool check = false;
        while(q >= 0) {
            if(copy[i][p] == copy[i][q] && !check) {
                copy[i][p] = copy[i][p] * 2;
                copy[i][q] = 0;
                check = true;
            }
            else {
                copy[i][--p] = copy[i][q];
                if(p != q)
                    copy[i][q] = 0;
                check = false;
            }
            q--;
            while(q >= 0 && !copy[i][q])
                q--;
        }
    }
}

void brute_force(int depth, int (*arr)[20])
{
    if(depth > 5)
        return;
    
    int copy[20][20];
    for(int d = 0; d < 4; ++d) {
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                copy[i][j] = arr[i][j];
            }
        }

        move[d](copy);
        brute_force(depth + 1, copy);

        if(depth == 5) {
            for(int i = 0; i < n; ++i) {
                for(int j = 0; j < n; ++j) {
                    if(max_block < copy[i][j])
                        max_block = copy[i][j];
                }
            }
        }
    }
}

void run()
{
    move[0] = push_up;
    move[1] = push_down;
    move[2] = push_left;
    move[3] = push_right;

    brute_force(1, arr);

    printf("%d\n", max_block);
}

int main()
{
    input();
    run();

    return 0;
}