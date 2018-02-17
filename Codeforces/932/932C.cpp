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

ll exgcd(ll a, ll b, ll& x, ll& y)
{
    ll d = a;
    if (b)
        d = exgcd(b, a % b, y, x), y -= x * (a / b);
    else
        x = 1, y = 0;
    return d;
}

#define Mod(a, b) (((a) % (b) + (b)) % (b))
bool solve(ll a, ll b, ll c, ll& x, ll& y, ll& dx, ll& dy)
{
    if (a == 0 && b == 0) return 0;
    ll x0, y0;
    ll d = exgcd(a, b, x0, y0);
    if (c % d != 0) return 0;
    dx = b / d, dy = a / d;
    x = Mod(x0 * c / d, dx);
    y = (c - a * x) / b;
    //  y = Mod(y0 * c / d, dy); x = (c - b * y) / a;
    return 1;
}

const int N = 1 << 20;
int v[N];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n, a, b;
    while (~scanf("%d%d%d", &n, &a, &b))
    {
        if (b < a) swap(a, b);
        clr(v, 0);
        ll x, y, dx, dy;
        if (solve(a, b, n, x, y, dx, dy) && y >= 0)
        {
            int p = 0, q = 1;
            while (x--)
            {
                int t = a, r = q++;
                while (t--)
                {
                    if (t == 0)
                        v[p++] = r;
                    else
                        v[p++] = q++;
                }
            }
            while (y--)
            {
                int t = b, r = q++;
                while (t--)
                {
                    if (t == 0)
                        v[p++] = r;
                    else
                        v[p++] = q++;
                }
            }
            for (int i = 0; i < n; i++) printf("%d ", v[i]);
        }
        else
            puts("-1");
    }
    return 0;
}