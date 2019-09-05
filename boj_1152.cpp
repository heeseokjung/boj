#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

int num_words = 0;
string arr;

void input()
{
    getline(cin, arr);
}

void run()
{
    int pivot = 0;
    while(arr[pivot] != '\0' && arr[pivot] == ' ')
        pivot++;
    if(arr[pivot] == '\0') {
        printf("0\n");
        return;
    }
    while(arr[pivot] != '\0') {
        if((arr[pivot] != ' ' && arr[pivot+1] == ' ') || (arr[pivot] != ' ' && arr[pivot+1] == '\0'))
            num_words++;
        pivot++;
    }

    printf("%d\n", num_words);
}

int main()
{
    input();
    run();

    return 0;
}