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
const double eps = 1e-8;

#define zero(x) ((fabs(x) < eps ? 1 : 0))
#define sgn(x) (fabs(x) < eps ? 0 : ((x) < 0 ? -1 : 1))

struct point
{
    double x, y;
    point(double a = 0, double b = 0)
    {
        x = a;
        y = b;
    }
    point operator-(const point& b) const
    {
        return point(x - b.x, y - b.y);
    }
    point operator+(const point& b) const
    {
        return point(x + b.x, y + b.y);
    }
    // 两点是否重合
    bool operator==(point& b)
    {
        return zero(x - b.x) && zero(y - b.y);
    }
    // 点积(以原点为基准)
    double operator*(const point& b) const
    {
        return x * b.x + y * b.y;
    }
    // 叉积(以原点为基准)
    double operator^(const point& b) const
    {
        return x * b.y - y * b.x;
    }
    // 绕P点逆时针旋转a弧度后的点
    point rotate(point b, double a)
    {
        double dx, dy;
        (*this - b).split(dx, dy);
        double tx = dx * cos(a) - dy * sin(a);
        double ty = dx * sin(a) + dy * cos(a);
        return point(tx, ty) + b;
    }
    // 点坐标分别赋值到a和b
    void split(double& a, double& b)
    {
        a = x;
        b = y;
    }
};
struct line
{
    point s, e;
    line() {}
    line(point ss, point ee)
    {
        s = ss;
        e = ee;
    }
};

bool segxseg(line l1, line l2)
{
    return max(l1.s.x, l1.e.x) >= min(l2.s.x, l2.e.x) && max(l2.s.x, l2.e.x) >= min(l1.s.x, l1.e.x) && max(l1.s.y, l1.e.y) >= min(l2.s.y, l2.e.y) && max(l2.s.y, l2.e.y) >= min(l1.s.y, l1.e.y) && sgn((l2.s - l1.e) ^ (l1.s - l1.e)) * sgn((l2.e - l1.e) ^ (l1.s - l1.e)) <= 0 && sgn((l1.s - l2.e) ^ (l2.s - l2.e)) * sgn((l1.e - l2.e) ^ (l2.s - l2.e)) <= 0;
}

bool PointOnSeg(point p, line l)
{
    return sgn((l.s - p) ^ (l.e - p)) == 0 && sgn((p.x - l.s.x) * (p.x - l.e.x)) <= 0 && sgn((p.y - l.s.y) * (p.y - l.e.y)) <= 0;
}

int PointInPoly(point p, point poly[], int n)
{
    int cnt;
    line ray, side;
    cnt = 0;
    ray.s = p;
    ray.e.y = p.y;
    ray.e.x = -100000000000.0; // -INF,注意取值防止越界
    for (int i = 0; i < n; i++)
    {
        side.s = poly[i];
        side.e = poly[(i + 1) % n];
        if (PointOnSeg(p, side)) return 0;
        //如果平行轴则不考虑
        if (sgn(side.s.y - side.e.y) == 0)
            continue;
        if (PointOnSeg(side.s, ray))
        {
            if (sgn(side.s.y - side.e.y) > 0) cnt++;
        }
        else if (PointOnSeg(side.e, ray))
        {
            if (sgn(side.e.y - side.s.y) > 0) cnt++;
        }
        else if (segxseg(ray, side))
            cnt++;
    }
    return cnt % 2 == 1 ? 1 : -1;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n, kase = 0;
    scanf("%d", &n);
    while (n--)
    {
        double x, y;
        point A[4];
        for (int i = 0; i < 4; i++)
        {
            scanf("%lf%lf", &x, &y);
            A[i] = point(x, y);
        }
        scanf("%lf%lf", &x, &y);
        point P(x, y);
        printf("Case %d:\n", ++kase);
        puts(PointInPoly(P, A, 4) == 1 ? "In" : "No");
    }
    return 0;
}
