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

const int maxn = 1 << 17;
#define zero(x) ((fabs(x) < eps ? 1 : 0))
#define sgn(x) (fabs(x) < eps ? 0 : ((x) < 0 ? -1 : 1))

struct point
{
    double x, y;
    point(double a = 0, double b = 0) { x = a, y = b; }
    point operator-(const point& b) const { return point(x - b.x, y - b.y); }
    point operator+(const point& b) const { return point(x + b.x, y + b.y); }
    bool operator==(point& b) { return zero(x - b.x) && zero(y - b.y); }
    double operator*(const point& b) const { return x * b.x + y * b.y; }
} P[maxn];

double dist(point a, point b) { return sqrt((a - b) * (a - b)); }

point waixin(point a, point b, point c)
{
    double a1 = b.x - a.x, b1 = b.y - a.y, c1 = (a1 * a1 + b1 * b1) / 2;
    double a2 = c.x - a.x, b2 = c.y - a.y, c2 = (a2 * a2 + b2 * b2) / 2;
    double d = a1 * b2 - a2 * b1;
    return point(a.x + (c1 * b2 - c2 * b1) / d, a.y + (a1 * c2 - a2 * c1) / d);
}

bool judge(point a, point b, point c)
{
    double a1 = b.x - a.x, b1 = b.y - a.y;
    double a2 = c.x - a.x, b2 = c.y - a.y;
    double d = a1 * b2 - a2 * b1;
    return zero(d);
}

bool check(double r, point o, int n)
{
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (zero(dist(P[i], o) - r)) cnt++;
        if (cnt == (n + 1) / 2) return true;
    }
    return false;
}

int main()
{
#ifdef LOCAL
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n;
        double x, y;
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            scanf("%lf%lf", &x, &y);
            P[i] = point(x, y);
        }
        if (n == 1)
        {
            printf("%f %f %f\n", P[0].x - 1, P[0].y, 1.0);
            continue;
        }
        if (n <= 4)
        {
            point tmp = P[0] + P[1];
            printf("%f %f %f\n", tmp.x / 2, tmp.y / 2, dist(P[0], P[1]) / 2);
            continue;
        }
        for (;;)
        {
            int a = rand() % n, b = rand() % n, c = rand() % n;
            if (a == b || b == c || c == a) continue;
            if (judge(P[a], P[b], P[c])) continue;
            point o = waixin(P[a], P[b], P[c]);
            double r = dist(P[a], o);
            if (check(r, o, n))
            {
                printf("%f %f %f\n", o.x, o.y, r);
                break;
            }
        }
    }
    return 0;
}
