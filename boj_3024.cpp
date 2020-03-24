#include <iostream>
#include <string>
using namespace std;

int main() {
    int N;
    cin >> N;
    char arr[30][30];
    string s;
    for(int i = 0; i < N; ++i) {
        cin >> s;
        for(int j = 0; j < N; ++j)
            arr[i][j] = s[j];
    }

    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            if(arr[i][j] >= 65 && arr[i][j] <= 90) {
                int count = 0;
                int r = i, c = j+1;
                while((r >= 0 && r < N && c >= 0 && c <= N) && arr[i][j] == arr[r][c]) {
                    c++;
                    count++;
                }
                r = i, c = j-1;
                while((r >= 0 && r < N && c >= 0 && c <= N) && arr[i][j] == arr[r][c]) {
                    c--;
                    count++;
                }
                if(count + 1 >= 3) {
                    cout << arr[i][j] << "\n";
                    return 0;
                }

                count = 0;
                r = i-1, c = j;
                while((r >= 0 && r < N && c >= 0 && c <= N) && arr[i][j] == arr[r][c]) {
                    r--;
                    count++;
                }
                r = i+1, c = j;
                while((r >= 0 && r < N && c >= 0 && c <= N) && arr[i][j] == arr[r][c]) {
                    r++;
                    count++;
                }
                if(count + 1 >= 3) {
                    cout << arr[i][j] << "\n";
                    return 0;
                }

                count = 0;
                r = i+1, c = j+1;
                while((r >= 0 && r < N && c >= 0 && c <= N) && arr[i][j] == arr[r][c]) {
                    r++; c++;
                    count++;
                }
                r = i-1, c = j-1;
                while((r >= 0 && r < N && c >= 0 && c <= N) && arr[i][j] == arr[r][c]) {
                    r--; c--;
                    count++;
                }
                if(count + 1 >= 3) {
                    cout << arr[i][j] << "\n";
                    return 0;
                }

                count = 0;
                r = i-1; c = j+1;
                while((r >= 0 && r < N && c >= 0 && c <= N) && arr[i][j] == arr[r][c]) {
                    r--; c++;
                    count++;
                }
                r = i+1; c = j-1;
                while((r >= 0 && r < N && c >= 0 && c <= N) && arr[i][j] == arr[r][c]) {
                    r++; c--;
                    count++;
                }
                if(count + 1 >= 3) {
                    cout << arr[i][j] << "\n";
                    return 0;
                }
            }
        }
    }

    cout << "ongoing\n";

    return 0;
}