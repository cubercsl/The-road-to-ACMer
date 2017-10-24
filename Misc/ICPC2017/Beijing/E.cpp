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
    int id;
    bool col;
    point() {}
    point(double _x, double _y) : x(_x), y(_y) {}
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

double dis(point A, point B)
{
    double dx = A.x - B.x;
    double dy = A.y - B.y;
    return sqrt(dx * dx + dy * dy);
}

void judge(point* A)
{
    line l1, l2;
    l1 = line(A[0], A[2]);
    l2 = line(A[1], A[3]);
    if (segxseg(l1, l2))
    {
        A[0].col = A[2].col = 0;
        A[1].col = A[3].col = 1;
        return;
    }
    l1 = line(A[0], A[3]);
    l2 = line(A[1], A[2]);
    if (segxseg(l1, l2))
    {
        A[0].col = A[3].col = 0;
        A[1].col = A[2].col = 1;
        return;
    }
    if (dis(A[0], A[1]) + dis(A[3], A[0]) < dis(A[2], A[0]) + dis(A[2], A[3]))
    {
        A[1].col = 1;
        A[0].col = A[2].col = A[3].col = 0;
    }
    else
    {
        A[2].col = 1;
        A[0].col = A[1].col = A[3].col = 0;
    }
    return;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int T;
    point A[105];
    scanf("%d", &T);
    while (T--)
    {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            double x, y;
            scanf("%lf%lf", &x, &y);
            A[i] = point(x, y);
            A[i].id = i;
        }
        if (n < 3)
        {
            puts("NO");
            continue;
        }
        sort(A, A + n, [](point a, point b) { return a.x < b.x || (a.x == b.x && a.y < b.y); });
        if (n == 3)
        {
            double dx1 = A[1].x - A[0].x;
            double dx2 = A[2].x - A[1].x;
            double dy1 = A[1].y - A[0].y;
            double dy2 = A[2].y - A[1].y;
            if (zero(dx1 * dy2 - dx2 * dy1))
            {
                A[0].col = A[2].col = 1;
                A[1].col = 0;
                sort(A, A + n, [](point a, point b) { return a.id < b.id; });
            }
            else
            {
                puts("NO");
                continue;
            }
        }
        else
        {
            judge(A);
            for (int i = 4; i < n; i++)
                A[i].col = 0;
            sort(A, A + n, [](point a, point b) { return a.id < b.id; });
        }
        puts("YES");
        for (int i = 0; i < n; i++)
            printf("%c", A[i].col ? 'B' : 'A');
        puts("");
    }
    return 0;
}
