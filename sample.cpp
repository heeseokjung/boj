#include <iostream>

#include <string>

#include <cstdio>
#include <cstring>

using namespace std;

 

const long long MOD = 100000;

const int MAX = 200;

 

int N;

string s;

long long cache[MAX][MAX];

string open = "({[", close = ")}]";

 

 

long long func(int start, int end, int d)

{

        //조건 만족

        if (start > end)

                 return 1;

 

        long long &result = cache[start][end];

        if (result != -1)

                 return result;

 

        result = 0;

        //+=2인 이유는 그 사이도 쌍이 생겨야하므로

        for (int i = start + 1; i <= end; i += 2)

                 for(int j=0; j<open.size(); j++)

                         if(s[start] == open[j] || s[start] == '?')

                                 if (s[i] == close[j] || s[i] == '?')

                                 {
                                          //start와 짝이 맞는 괄호의 위치 i

                                          //따라서 (start+1) ~ (i-1) 과 (i+1) ~ end 구간을 분할 탐색
                                        printf("s: %d e: %d d: %d i: %d\n", start, end, d, i);
                                          long long temp = func(start + 1, i - 1, d+1) * func(i + 1, end, d+1);

                                          result += temp;

                                          if (result >= MOD) {
                                                  result = MOD + result % MOD;
                                          }

                                 }

        return result;

}

 

int main(void)

{

        //ios_base::sync_with_stdio(0);

        //cin.tie(0);

        cin >> N >> s;

 

        memset(cache, -1, sizeof(cache));

        long long result = func(0, N - 1, 0);

 

        if (result >= MOD)

                 printf("%05lld\n", result%MOD);

        else

                 cout << result << "\n";
                 /*
        for(int i = 0; i < N; ++i)
                for(int j = 0; j < N; ++j)
                        printf("i: %d j: %d cache: %lld\n", i, j, cache[i][j]);
                        */

        return 0;

}