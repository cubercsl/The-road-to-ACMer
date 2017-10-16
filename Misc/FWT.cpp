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

ll a[1 << 17], b[1 << 17];
ll mo;

ll Mul(ll a, ll b)
{
    return ((a * b - ll(((ld)a) / mo * b + 1e-3) * mo) % mo + mo) % mo;
}

ll Pow(ll a, ll n)
{
    a %= mo;
    ll t = 1;
    for (; n; n >>= 1, a = Mul(a, a))
        if (n & 1) t = Mul(t, a);
    return t;
}

void fwt(ll* a, int l, int r)
{
    if (l == r) return;
    int mid = l + r >> 1, len = mid - l + 1;
    fwt(a, l, mid);
    fwt(a, mid + 1, r);
    for (int i = l; i <= mid; i++)
    {
        ll u = a[i], v = a[i + len];
        a[i] = (u + v) % mo;
        a[i + len] = (u - v) % mo;
    }
}

void ifwt(ll* a, int l, int r)
{
    if (l == r) return;
    int mid = l + r >> 1, len = mid - l + 1;
    for (int i = l; i <= mid; i++)
    {
        ll u = a[i], v = a[i + len];
        a[i] = (u + v) % mo;
        a[i + len] = (u - v) % mo;
    }
    ifwt(a, l, mid);
    ifwt(a, mid + 1, r);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n;
    while (~scanf("%d", &n))
    {
        for (int i = 0; i < n; i++)
            scanf("%lld", a + i);
        for (int i = 0; i < n; i++)
            scanf("%lld", b + i);
        int N = 1;
        while (N < n) N <<= 1;
        mo = 1LL * mod * N;
        for (int i = n; i < N; i++)
            a[i] = b[i] = 0;
        fwt(a, 0, N - 1);
        fwt(b, 0, N - 1);
        for (int i = 0; i < N; i++)
            a[i] = Mul(a[i], b[i]);
        ifwt(a, 0, N - 1);
        for (int i = 0; i < N; i++)
            a[i] = (a[i] + mo) % mo / N;
        for (int i = 0; i < n; i++)
        {
            if (i) putchar(' ');
            printf("%lld", a[i]);
        }
        puts("");
    }
    return 0;
}
