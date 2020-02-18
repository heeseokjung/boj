#include<iostream>
#include<queue>
#include<vector>
 
#define endl "\n"
#define MAX 100000 + 1
using namespace std;
 
int N, K, M;
int Cost[MAX + 1000];
vector<int> Station[MAX + 1000];
 
void Input()
{
    cin >> N >> K >> M;
    for (int i = 1; i <= M; i++)
    {
        for (int j = 0; j < K; j++)
        {
            int a; cin >> a;
            Station[a].push_back(i + N);
            Station[i + N].push_back(a);
        }
    }
}
 
int BFS()
{
    queue<int> Q;
    Q.push(1);
    Cost[1] = 1;
 
    while (Q.empty() == 0)
    {
        int Cur = Q.front();
        Q.pop();
 
        if (Cur == N) return Cost[Cur];
 
        if(Cur == 132)
            cout << "size: " << Station[Cur].size() << endl;
        for (int i = 0; i < Station[Cur].size(); i++)
        {
            int Next = Station[Cur][i];
            if (Cost[Next] == 0)
            {
                if (Next > N) Cost[Next] = Cost[Cur];
                else Cost[Next] = Cost[Cur] + 1;
                Q.push(Next);
            }
        }
    }
    return -1;
}
 
void Solution()
{
    int Answer = BFS();
    cout << Answer << endl;
}
 
void Solve()
{
    Input();
    Solution();
}
 
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    //freopen("Input.txt", "r", stdin);
    Solve();
    for(int i = 1; i <= N; ++i) 
       cout << i << " -> " << Station[i].size() << endl;
 
    return 0;
}
