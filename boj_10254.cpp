#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int N, TC;
typedef struct Point {
    long long x; 
    long long y;
    Point() {}
    Point(long long _x, long long _y) : x(_x), y(_y) {}
    Point(const Point& o) : x(o.x), y(o.y) {}
}Point;
Point p;
vector<Point> v;

inline int ccw(Point& p1, Point& p2, Point& p3) {
    long long c = (p2.x - p1.x)*(p3.y - p1.y) - (p2.y - p1.y)*(p3.x - p1.x);
    if(c > 0)
        return 1;
    else if(c < 0)
        return -1;
    else
        return 0;
}   

inline int cross_product(Point& p, Point& q) {
    return p.x*q.y - p.y*q.x;
}

inline long long dist(Point& p, Point& q) {
    return (q.x - p.x)*(q.x - p.x) + (q.y - p.y)*(q.y - p.y);
}

bool cmp(Point& u, Point& v) {
    int c = ccw(p, u, v);
    if(c == 0)
        return dist(p, u) <= dist(p, v);
    else
        return c > 0;
}

int main() {
    scanf("%d", &TC);
    while(TC--) {
        scanf("%d", &N);
        v.clear();
        v.reserve(N);
        long long x, y;
        for(int i = 0; i < N; ++i) {
            scanf("%lld %lld", &x, &y);
            v.push_back(Point(x, y));
        }

        p = Point(v[0]);
        for(int i = 1, size = (int)v.size(); i < size; ++i) {
            if(v[i].y < p.y || (v[i].y == p.y && v[i].x < p.x))
                p = v[i];
        }
        sort(v.begin(), v.end(), cmp);
        vector<Point> s;
        for(int i =  0, size = (int)v.size(); i < size; ++i) {
            while(s.size() >= 2 && ccw(s[s.size()-2], s[s.size()-1], v[i]) <= 0)
                s.pop_back();
            s.push_back(v[i]);
        }

        Point p1, p2;
        long long ans = 0;
        int size = (int)s.size(), j = 1;
        for(int i = 0; i < size; ++i) {
            while(true) {
                Point a = Point(s[(i+1)%size].x - s[i].x, s[(i+1)%size].y - s[i].y);
                Point b = Point(s[(j+1)%size].x - s[j%size].x, s[(j+1)%size].y - s[j%size].y);
                if(cross_product(a, b) <= 0)
                    break;
                j = (j + 1)%size;
            }
            long long d = dist(s[i], s[j]);
            if(d > ans) {
                ans = d;
                p1.x = s[i].x, p1.y = s[i].y;
                p2.x = s[j].x, p2.y = s[j].y;
            }
        }
        printf("%lld %lld %lld %lld\n", p1.x, p1.y, p2.x, p2.y);
    }
}