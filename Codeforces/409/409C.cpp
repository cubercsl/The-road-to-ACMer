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

const int maxn = 1 << 17;
double a[maxn], b[maxn];
int n, p;
bool judge(double t)
{
    double ext = p * t;
    for (int i = 0; i < n; i++)
    {
        double tmp = a[i] * t - b[i];
        if (tmp > 0) ext -= tmp;
        if (ext < 0) return false;
    }
    return true;
}

int main()
{
#ifndef ONLINE_JUDGE
// freopen("1.in", "r", stdin);
// freopen("1.out", "w", stdout);
#endif
    while (cin >> n >> p)
    {
        double sum = 0;
        for (int i = 0; i < n; i++)
            cin >> a[i] >> b[i], sum += a[i];
        if (p - sum > -eps)
        {
            cout << -1 << endl;
            continue;
        }
        double l = 0, r = 1e12;
        while (r - l > eps)
        {
            double m = (l + r) / 2;
            if (judge(m))
                l = m;
            else
                r = m;
        }
        cout << l << endl;
    }
    return 0;
}
