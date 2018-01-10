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

vector<PII> v;

inline void s()
{
    static int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int cnt = 0;
    for (auto p : v)
        if (p.X > x1 && p.X < x2 && p.Y > y1 && p.Y < y2) cnt++;
    cout << cnt << endl;
}

inline void r()
{
    static int x, y, r;
    cin >> x >> y >> r;
    int cnt = 0;
    for (auto p : v)
        if ((p.X - x) * (p.X - x) + (p.Y - y) * (p.Y - y) < r * r) cnt++;
    cout << cnt << endl;
}

PII operator-(const PII& a, const PII& b)
{
    return mp(a.X - b.X, a.Y - b.Y);
}

int operator*(const PII& a, const PII& b)
{
    return a.X * b.Y - a.Y * b.X;
}

bool ok(PII a, PII p[])
{
    int tmp[3];
    for (int i = 0; i < 3; i++)
        tmp[i] = (p[i] - a) * (p[(i + 1) % 3] - a);
    return (tmp[0] > 0 && tmp[1] > 0 && tmp[2] > 0)
        || (tmp[0] < 0 && tmp[1] < 0 && tmp[2] < 0);
}

inline void t()
{
    PII a[3];
    int cnt = 0;
    for (int i = 0; i < 3; i++) cin >> a[i].X >> a[i].Y;
    for (auto p : v)
        if (ok(p, a)) cnt++;
    cout << cnt << endl;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int T;
    cin >> T;
    while (T--)
    {
        v.clear();
        int n, q;
        cin >> n >> q;
        int x, y;
        while (n--)
        {
            cin >> x >> y;
            v.pb(mp(x, y));
        }
        sort(v.begin(), v.end());
        while (q--)
        {
            static char op;
            cin >> op;
            if (op == 'R') r();
            if (op == 'S') s();
            if (op == 'T') t();
        }
        cout << endl;
    }
    return 0;
}
