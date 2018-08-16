#include <bits/stdc++.h>
using namespace std;
#define clr(a, x) memset(a, x, sizeof(a))
#define mp make_pair
#define pb push_back
#define X first
#define Y second
typedef long long ll;
typedef long double ld;
typedef pair<int, int> PII;
typedef vector<int> VI;
const int INF = 0x3f3f3f3f;
const int p = 998244353;
const double eps = 1e-6;
const int maxn = 200010;
ll f[maxn];
ll inv[maxn]; // 阶乘的逆元
ll Pow(ll a, ll n, ll mod)
{
    ll t = 1;
    for (; n; n >>= 1, a = (a * a % mod))
        if (n & 1)
            t = (t * a % mod);
    return t;
}
void CalFact()
{
    f[0] = 1;
    for (int i = 1; i < maxn; i++)
        f[i] = (f[i - 1] * i) % p;
    inv[maxn - 1] = Pow(f[maxn - 1], p - 2, p);
    for (int i = maxn - 2; ~i; i--)
        inv[i] = inv[i + 1] * (i + 1) % p;
}
ll C(int n, int m) { return f[n] * inv[m] % p * inv[n - m] % p; }

int main()
{

#ifndef ONLINE_JUDGE
    // freopen("1.in", "r", stdin);
    // freopen("1.out", "w", stdout);
#endif

    int T, n, m, k;
    CalFact();
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d%d", &n, &m, &k);
        int tm = m - 1, tn = m + k - 1;
        //cout << tn << " " << tm << endl;
        ll ans = C(tn, tm);
        //cout << ans << endl;
        if (n <= k)
        {
            for (int i = 1; i <= m; i++)
            {
                if (tn - n * i < tm)
                    break;
                if (i & 1)
                {
                    ans -= C(m, i) * C(tn - n * i, tm) % p;
                }
                else
                {
                    ans += C(m, i) * C(tn - n * i, tm) % p;
                }
                //cout << C(m, i) << " " << C(tn - n * i, tm) << " " <<tn - n<<endl;
                //cout << ans << endl;
                ans = (ans + p) % p;
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}