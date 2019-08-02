#include <stdio.h>
#include <map>
using namespace std;

int N, S;
long long seq[40];
int seq1_end, seq2_end;
map<long long, long long> seq_sum;
long long ans = 0;

void input()
{
    scanf("%d %d", &N, &S);
    for(int i = 0; i < N; ++i)
        scanf("%lld", seq + i);
}

void dfs_seq1(int pos, int count, long long sum)
{
    if(pos == seq1_end) {
        if(count) {
            if(sum == S)
                ans++;
            auto it = seq_sum.find(sum);
            if(it != seq_sum.end())
                ++it->second;
            else
                seq_sum.insert(make_pair(sum, 1));
        }
        return;
    }
    dfs_seq1(pos + 1, count, sum);
    dfs_seq1(pos + 1, count + 1, sum + seq[pos]);
}

void dfs_seq2(int pos, int count, long long sum)
{
    if(pos == seq2_end) {
        if(count) {
            if(sum == S)
                ans++;
            auto it = seq_sum.find(S - sum);
            if(it != seq_sum.end())
                ans += it->second;
        }
        return;
    }
    dfs_seq2(pos + 1, count, sum);
    dfs_seq2(pos + 1, count + 1, sum + seq[pos]);
}

void run()
{
    seq1_end = N/2;
    seq2_end = N;
    dfs_seq1(0, 0, 0);
    dfs_seq2(N/2, 0, 0);

    printf("%lld\n", ans);
}

int main()
{
    input();
    run();
    return 0;
}