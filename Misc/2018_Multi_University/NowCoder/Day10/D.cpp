#include <bits/stdc++.h>
using namespace std;

const int mod = 119 << 23 | 1;
typedef long long ll;
const int N = 1 << 17;

const int p = 119 << 23 | 1;
const int maxn = 1 << 18;
ll Pow(ll a, ll n = p - 2, ll p = mod)
{
    ll t = 1;
    for (; n; n >>= 1, (a *= a) %= p)
        if (n & 1) (t *= a) %= p;
    return t;
}
ll f[maxn];
ll inv[maxn]; // 阶乘的逆元
void CalFact()
{
    f[0] = 1;
    for (int i = 1; i < maxn; i++) f[i] = (f[i - 1] * i) % p;
    inv[maxn - 1] = Pow(f[maxn - 1], p - 2, p);
    for (int i = maxn - 2; ~i; i--) inv[i] = inv[i + 1] * (i + 1) % p;
}
ll C(int n, int m)
{
    if (n < m) return 0;
    return f[n] * inv[m] % p * inv[n - m] % p;
}

inline ll Add(ll x, ll y)
{
    ll ret = x + y;
    if (ret >= mod) ret -= mod;
    return ret;
}
inline ll Sub(ll x, ll y)
{
    ll ret = x - y;
    if (ret < 0) ret += mod;
    return ret;
}
inline ll Mul(ll x, ll y)
{
    ll ret = x * y;
    if (ret >= mod) ret %= mod;
    return ret;
}

int main()
{
    CalFact();
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n, q, max_d = 1;
        vector<tuple<int, int, int> > ops;
        scanf("%d%d", &n, &q);
        while (q--)
        {
            static int op, l, r, x;
            scanf("%d", &op);
            if (op == 1)
            {
                scanf("%d%d%d", &l, &r, &x);
                ops.emplace_back(l, max_d - 1, x);
                ops.emplace_back(r + 1, max_d - 1, -x);
            }
            else if (op == 2)
                max_d++;
            else
            {
                scanf("%d%d", &l, &r);
                ll ans = 0;
                for (auto& it : ops)
                {
                    int L, D, V;
                    tie(L, D, V) = it;
                    D = max_d - D;
                    if (L <= l - 1)
                    {
                        ans = Sub(ans, Mul(V, C(l - L + D - 1, l - L - 1)));
                        ans = ans % mod + mod;
                        ans %= mod;
                    }
                    if (L <= r)
                    {
                        ans = Add(ans, Mul(V, C(r - L + D, r - L)));
                        ans = ans % mod + mod;
                        ans %= mod;
                    }
                }
                printf("%lld\n", ans);
            }
        }
    }
}