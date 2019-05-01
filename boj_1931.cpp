// boj_1931

#include <cstdio>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int num_conf;
    scanf("%d", &num_conf);
    int start, end;
    vector<pair<long long, long long> > rschedule;
    for(int i = 0; i < num_conf; ++i) {
        scanf("%d %d", &start, &end);
        rschedule.push_back(make_pair(end, start));
    }

    sort(rschedule.begin(), rschedule.end());

    long long cur_end = 0;
    int max_num = 0;
    for(int i = 0; i < num_conf; ++i) {
        if(rschedule[i].second >= cur_end) {
            max_num++;
            cur_end = rschedule[i].first;
        }
    }

    printf("%d\n", max_num);
    
    return 0;
}