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

#define zero(x) ((fabs(x) < eps ? 1 : 0))
#define sgn(x) (fabs(x) < eps ? 0 : ((x) < 0 ? -1 : 1))

struct point
{
    double x, y;
    point(double a = 0, double b = 0) { x = a, y = b; }
    point operator-(const point& b) const { return point(x - b.x, y - b.y); }
    point operator+(const point& b) const { return point(x + b.x, y + b.y); }
    // 两点是否重合
    bool operator==(point& b) { return zero(x - b.x) && zero(y - b.y); }
    // 点积(以原点为基准)
    double operator*(const point& b) const { return x * b.x + y * b.y; }
    // 叉积(以原点为基准)
    double operator^(const point& b) const { return x * b.y - y * b.x; }
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
    void split(double& a, double& b) { a = x, b = y; }
};
struct line
{
    point s, e;
    line() {}
    line(point ss, point ee) { s = ss, e = ee; }
};

bool segxseg(line l1, line l2)
{
    return max(l1.s.x, l1.e.x) >= min(l2.s.x, l2.e.x) && max(l2.s.x, l2.e.x) >= min(l1.s.x, l1.e.x) && max(l1.s.y, l1.e.y) >= min(l2.s.y, l2.e.y) && max(l2.s.y, l2.e.y) >= min(l1.s.y, l1.e.y) && sgn((l2.s - l1.e) ^ (l1.s - l1.e)) * sgn((l2.e - l1.e) ^ (l1.s - l1.e)) <= 0 && sgn((l1.s - l2.e) ^ (l2.s - l2.e)) * sgn((l1.e - l2.e) ^ (l2.s - l2.e)) <= 0;
}

bool check(const vector<point>& r, const vector<point>& b, const vector<int>& id)
{
    int n = r.size();
    vector<line> v(n);
    for (int i = 0; i < n; i++)
        v[i] = line(r[i], b[id[i]]);
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (segxseg(v[i], v[j])) return false;
    return true;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int R, B;
    cin >> R >> B;
    if (R != B) return cout << "No", 0;
    vector<point> r(R);
    vector<point> b(B);
    for (auto& t : r) cin >> t.x >> t.y;
    for (auto& t : b) cin >> t.x >> t.y;
    vector<int> id(R);
    iota(id.begin(), id.end(), 0);
    do
    {
        if (check(r, b, id)) return cout << "Yes", 0;
    } while (next_permutation(id.begin(), id.end()));
    cout << "No";
    return 0;
}