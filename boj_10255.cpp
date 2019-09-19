#include <stdio.h>
#include <utility>
#include <vector>
using namespace std;

typedef struct Line
{
    pair<int, int> p;
    pair<int, int> q;
}Line;

inline void swap(int& x, int& y)
{
    if(x > y) {
        int tmp = x;
        x = y;
        y = tmp;
    }
}

int ccw(pair<int, int> p1, pair<int, int> p2, pair<int, int> p3)
{
    int c = (p2.first - p1.first)*(p3.second - p1.second) - 
            (p2.second - p1.second)*(p3.first - p1.first);
    if(c > 0)
        return 1;
    else if(c < 0)
        return -1;
    else
        return 0;
}

int intersect(Line line1, Line line2)
{
    if(!ccw(line1.p, line1.q, line2.p) && !ccw(line1.p, line1.q, line2.q)) {
        int a = line1.p.first + line1.p.second, b = line1.q.first + line1.q.second;
        int c = line2.p.first + line2.p.second, d = line2.q.first + line2.q.second;
        swap(a, b); swap(c, d);
        if(b < c || d < a)
            return 0;
        else if(b == c || a == d)
            return 1;
        else
            return -1;
    }
    if(ccw(line1.p, line1.q, line2.p) == ccw(line1.p, line1.q, line2.q) ||
       ccw(line2.p, line2.q, line1.p) == ccw(line2.p, line2.q, line1.q))
            return 0;
    return 1;
}

void run()
{
    int i;
    int TC, xmin, ymin, xmax, ymax;
    int x1, y1, x2, y2;
    typedef pair<int, int> ii;
    vector<Line> v;
    scanf("%d", &TC);
    while(TC--) {
        scanf("%d %d %d %d", &xmin, &ymin, &xmax, &ymax);
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        int count = 0, dup = 0;
        Line line1 {ii(x1, y1), ii(x2, y2)};
        v.clear();
        v.push_back(Line {ii(xmin, ymin), ii(xmax, ymin)});
        v.push_back(Line {ii(xmax, ymin), ii(xmax, ymax)});
        v.push_back(Line {ii(xmax, ymax), ii(xmin, ymax)});
        v.push_back(Line {ii(xmin, ymax), ii(xmin, ymin)});
        for(i = 0; i < 4; ++i) {
            int c = intersect(line1, v[i]);
            if(c == -1) {
                count = 4;
                break;
            }
            if(ccw(ii(x1, y1), ii(x2, y2), v[i].p) * ccw(ii(x1, y1), ii(x2, y2), v[i].q) == 0
            && ccw(v[i].p, v[i].q, ii(x1, y1)) * ccw(v[i].p, v[i].q, ii(x2, y2)) <= 0)
                dup++;
            count += c;
        }
        if(i == 4)
            count -= (dup / 2);
        printf("%d\n", count);
    }   
}

int main()
{
    run();
    return 0;
}