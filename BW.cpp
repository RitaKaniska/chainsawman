#include<bits/stdc++.h>
#define int long long

using namespace std;

typedef long double ld;

struct Point
{
    ld x,y;
};

bool operator==(Point x, Point y)
{
    return ((x.x == y.x) && (x.y == y.y));
}
Point operator+(Point x, Point y)
{
    return {x.x + y.x, x.y + y.y};
}
Point operator-(Point x, Point y)
{
    return {x.x - y.x, x.y - y.y};
}
Point operator*(Point x, Point y)
{
    return {x.x * y.x, x.y * y.y};
}
Point operator/(Point x, Point y)
{
    return {x.x / y.x, x.y / y.y};
}
ld crossproduct(Point a, Point b , Point c)
{
    Point u = b - a;
    Point v = c - a;
    return u.x * v.y - u.y * v.x;
}
ld dotproduct(Point a, Point b , Point c)
{
    Point u = b - a;
    Point v = c - a;
    return u.x * v.x + u.y * v.y;
}

bool comparePoints(const Point &a, const Point &b)
{
    return (a.x == b.x) ? (a.y < b.y) : (a.x < b.x);
}
bool ismidpoint(Point a, Point b, Point c)
{
    vector<Point> v = {a,b,c};
    sort(v.begin(),v.end(),comparePoints);
    return (v[1] == c);
}
ld sign(ld x)
{
    return (x > 0) - (x < 0);
}

bool Intersect(Point a,Point b,Point c,Point d)
{
    ld cross1 =  crossproduct(a,b,c);
    ld cross2 =  crossproduct(a,b,d);
    ld cross3 =  crossproduct(c,d,a);
    ld cross4 =  crossproduct(c,d,b);
    if(cross1 == 0 && ismidpoint(a,b,c)) return true;
    if(cross2 == 0 && ismidpoint(a,b,d)) return true;
    if(cross3 == 0 && ismidpoint(c,d,a)) return true;
    if(cross4 == 0 && ismidpoint(c,d,b)) return true;
    if(sign(cross1) != sign(cross2) && sign(cross3) != sign(cross4)) return true;
    return false;
}

void solve()
{
    Point a,b,c,d;
    cin >> a.x >> a.y;
    cin >> b.x >> b.y;
    cin >> c.x >> c.y;
    cin >> d.x >> d.y;
    if(Intersect(a,b,c,d)) cout << "YES" <<endl;
    else cout << "NO" <<endl;
}
signed main()
{
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
}