#include <bits/stdc++.h>
using namespace std;
#define clr(a,x) memset(a, x, sizeof(a))
#define mp(x,y) make_pair(x,y)
#define pb(x) push_back(x)
#define X first
#define Y second
#define fastin ios_base::sync_with_stdio(0);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef pair<int, int> PII;
typedef vector<int> VI;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-10;

#define pi M_PI
#define zero(x) ((fabs(x)<eps?1:0))
#define sgn(x) (fabs(x)<eps?0:((x)<0?-1:1))

struct point
{
    double x, y;
    point(double a = 0, double b = 0)
    {
        x = a;
        y = b;
    }
    point operator - (const point& b) const
    {
        return point(x - b.x, y - b.y);
    }
    point operator + (const point &b) const
    {
        return point(x + b.x, y + b.y);
    }
    // 两点是否重合
    bool operator == (point& b)
    {
        return zero(x - b.x) && zero(y - b.y);
    }
    // 点积(以原点为基准)
    double operator * (const point &b) const
    {
        return x * b.x + y * b.y;
    }
    // 叉积(以原点为基准)
    double operator ^ (const point &b) const
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
    void split(double &a, double &b)
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

double dist(point a, point b)
{
    return sqrt((a - b) * (a - b));
}

point pointtosegment(point p, line l)
{
    point res;
    double t = ((p - l.s) * (l.e-l.s)) / ((l.e-l.s) * (l.e-l.s));
    if (t >= 0 && t <= 1)
    {
        res.x = l.s.x + (l.e.x - l.s.x) * t;
        res.y = l.s.y + (l.e.y - l.s.y) * t;
    }
    else res = dist(p, l.s) < dist(p, l.e) ? l.s : l.e;
    return res;
}

int main()
{
    fastin
    int T;
    cin >> T;
    while (T--)
    {
        double x, y, R;
        cin >> x >> y >> R;
        point C = point(x, y);
        point A[3];
        for (int i = 0; i < 3; i++)
        {
            cin >> x >> y;
            A[i] = point(x, y);
        }
        int cnt = 0;
        for (int i = 0; i < 3; i++)
        {
            double dis = dist(A[i], C);
            if (dis < R) cnt++;
        }
        if (cnt == 3) // 三点都在圆内
            cout << "No" << endl;
        else if (cnt == 0) // 三点都在圆外
        {
            bool flag = 1;
            for (int i = 0; i < 3; i++)
            {
                line L = line(A[i], A[(i + 1) % 3]);
                point tmp = pointtosegment(C, L);
                double dis = tmp.x * tmp.x + tmp.y * tmp.y;
                if (dis <= R * R)
                {
                    flag = 0;
                    cout << "Yes" << endl;
                    break;
                }
            }
            if (flag) cout << "No" << endl;
        }
        else cout << "Yes" << endl;
    }
    return 0;
}
