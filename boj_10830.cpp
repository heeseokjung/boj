#include <cstdio>
#include <map>
#define MOD 1000
using namespace std;

typedef struct Matrix {
    long long pow;
    int arr[5][5];
}Matrix;

int N;
long long B;
map<long long, Matrix> check;

Matrix matmul(Matrix m1, Matrix m2) {
    Matrix m3;
    m3.pow = m1.pow + m2.pow;
    for(int i = 0; i < N; ++i)
        for(int j = 0; j < N; ++j)
            m3.arr[i][j] = 0;
    
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            for(int k = 0; k < N; ++k) {
                m3.arr[i][j] += m1.arr[i][k] * m2.arr[k][j];
            }
            m3.arr[i][j] %= MOD;
        }
    }

    return m3;
}

Matrix matpow(Matrix m, long long pow) {
    if(pow == 1)
        return m;
    auto it = check.find(pow);
    if(it != check.end())
        return it->second;
    long long p1 = pow / 2LL;
    long long p2 = pow - p1;
    Matrix tmp = matmul(matpow(m, p1), matpow(m, p2));
    check.insert({pow, tmp});
    return tmp;
}

int main() {
    scanf("%d %lld", &N, &B);
    Matrix m;
    m.pow = 1LL;
    for(int i = 0; i < N; ++i)
        for(int j = 0; j < N; ++j)
            scanf("%d", &m.arr[i][j]);

    check.insert({1, m});
    Matrix ans = matpow(m, B);

    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            printf("%d ", ans.arr[i][j] % MOD);
        }
        printf("\n");
    }
    
    return 0;
}