#include <cstdio>
#include <set>

using namespace std;

int main()
{
    set<int> s;
    for(int i = 1; i <= 30; ++i)
        s.insert(i);

    int sid;
    set<int>::iterator it;
    for(int i = 0; i < 28; ++i) {
        scanf("%d", &sid);
        it = s.find(sid);
        if(it != s.end())
            s.erase(it);
    }

    for(it = s.begin(); it != s.end(); ++it)
        printf("%d\n", *it);

    return 0;
}