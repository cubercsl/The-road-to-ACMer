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

struct point
{
    double x, y;
    point(double a = 0, double b = 0) { x = a, y = b; }
    point operator-(const point& b) const { return point(x - b.x, y - b.y); }
    point operator+(const point& b) const { return point(x + b.x, y + b.y); }
    point operator*(const double b) const { return point(b * x, b * y); }
    void print() { cout << x << " " << y << endl; }
};

const double T = 0.000005;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int kase = 0;
    double alpha, v0, y0, m, k;
    point g(0, -9.8);
    while (cin >> alpha >> v0 >> y0 >> m >> k)
    {
        cout << "Case " << ++kase << ":" << endl;
        point v(v0 * cos(alpha / 180 * M_PI), v0 * sin(alpha / 180 * M_PI));
        point t(0, y0);
        bool flag = 0;
        for (; !flag || t.y > 0;)
        {
            flag = 1;
            point a = (g * m - v * k) * (1 / m);
            t = t + v * T + a * T * T * 0.5;
            v = v + a * T;
            // t.print();
        }
        printf("%.2f\n", t.x);
    }
    return 0;
}
