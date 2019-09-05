#include <cstdio>
#include <queue>

using namespace std;

#define SWAP(a,b)  {(a)^=(b)^=(a)^=(b);}

int N;
int max_candy = 0;
char candy[51][51];
bool visit[51][51];

void run();
void dfs();

int main()
{
    scanf("%d", &N);
    char c;
    for(int i = 1; i <= N; ++i) {
        for(int j = 1; j <= N; ++j) {
            scanf(" %c", &c);
            candy[i][j] = c;
            visit[i][j] = false;
        }
    }

    run();
    
    return 0;
}

void run()
{
    for(int i = 1; i <= N; ++i) {
        for(int j = 1; j <= N; ++j) {
            visit[i][j] = true;

            if(i > 1 && candy[i][j] != candy[i-1][j] && !visit[i-1][j]) {
                SWAP(candy[i][j], candy[i-1][j]);
                dfs();
                SWAP(candy[i][j], candy[i-1][j]);
            }
            if(i < N && candy[i][j] != candy[i+1][j] && !visit[i+1][j]) {
                SWAP(candy[i][j], candy[i+1][j]);
                dfs();
                SWAP(candy[i][j], candy[i+1][j]);
            }
            if(j > 1 && candy[i][j] != candy[i][j-1] && !visit[i][j-1]) {
                SWAP(candy[i][j], candy[i][j-1]);
                dfs();
                SWAP(candy[i][j], candy[i][j-1]);
            }
            if(j < N && candy[i][j] != candy[i][j+1] && !visit[i][j+1]) {
                SWAP(candy[i][j], candy[i][j+1]);
                dfs();
                SWAP(candy[i][j], candy[i][j+1]);
            }
        }
    }

    printf("%d\n", max_candy);
}

void dfs()
{
    priority_queue<int> pq;

    int count;
    for(int i = 1; i <= N; ++i) {
        for(int j = 1; j <= N; ++j) {
            if(i > 1 && candy[i][j] == candy[i-1][j]) {
                count = 0;
                int k = i;
                while(k >= 1 && candy[k][j] == candy[i][j]) {
                    count++;
                    k--;
                }
                pq.push(count);
            }
            if(i < N && candy[i][j] == candy[i+1][j]) {
                count = 0;
                int k = i;
                while(k <= N && candy[k][j] == candy[i][j]) {
                    count++;
                    k++;
                }
                pq.push(count);
            }
            if(j > 1 && candy[i][j] == candy[i][j-1]) {
                count = 0;
                int k = j;
                while(k >= 1 && candy[i][k] == candy[i][j]) {
                    count++;
                    k--;
                }
                pq.push(count);
            }
            if(j < N && candy[i][j] == candy[i][j+1]) {
                count = 0;
                int k = j;
                while(k <= N && candy[i][k] == candy[i][j]) {
                    count++;
                    k++;
                }
                pq.push(count);
            }

            if(!pq.empty() && pq.top() > max_candy)
                max_candy = pq.top();
        }
    }
}
