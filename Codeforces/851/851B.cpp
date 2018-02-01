#include <bits/stdc++.h>
using namespace std;
#define clr(a, x) memset(a, x, sizeof(a))
#define mp(x, y) make_pair(x, y)
#define pb(x) push_back(x)
#define X first
#define Y second
#define fastin                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef pair<int, int> PII;
typedef vector<int> VI;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-6;

inline bool zero(double x) { return fabs(x) < eps; }
struct point
{
    double x, y;
    point(double a = 0, double b = 0) { x = a, y = b; }
    point operator-(const point& b) const { return point(x - b.x, y - b.y); }
    point operator+(const point& b) const { return point(x + b.x, y + b.y); }
    bool operator==(point& b) { return zero(x - b.x) && zero(y - b.y); }
    double operator*(const point& b) const { return x * b.x + y * b.y; }
    double operator^(const point& b) const { return x * b.y - y * b.x; }
};

point waixin(point a, point b, point c)
{
    double a1 = b.x - a.x, b1 = b.y - a.y, c1 = (a1 * a1 + b1 * b1) / 2;
    double a2 = c.x - a.x, b2 = c.y - a.y, c2 = (a2 * a2 + b2 * b2) / 2;
    double d = a1 * b2 - a2 * b1;
    return point(a.x + (c1 * b2 - c2 * b1) / d, a.y + (a1 * c2 - a2 * c1) / d);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    point a, b, c;
    while (cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y)
    {
        point o = waixin(a, b, c);
        point oa(a - o), ob(b - o), oc(c - o);
        if (zero(oa * ob - ob * oc))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}