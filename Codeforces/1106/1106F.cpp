#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod = 119 << 23 | 1;

typedef vector<ll> vec;
typedef vector<vec> mat;
mat mul(const mat& A, const mat& B, ll mod)
{
    mat C(A.size(), vec(B[0].size()));
    for (int i = 0; i < A.size(); i++)
        for (int k = 0; k < B.size(); k++)
            if (A[i][k])
                for (int j = 0; j < B[0].size(); j++)
                    C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % mod;
    return C;
}

mat Pow(mat A, ll n, ll mod)
{
    mat B(A.size(), vec(A.size()));
    for (int i = 0; i < A.size(); i++) B[i][i] = 1;
    for (; n; n >>= 1, A = mul(A, A, mod))
        if (n & 1) B = mul(B, A, mod);
    return B;
}

ll Pow(ll a, ll n, ll mod)
{
    ll t = 1;
    for (; n; n >>= 1, (a *= a) %= mod)
        if (n & 1) (t *= a) %= mod;
    return t;
}

ll exbsgs(ll a, ll b, ll p)
{
    if (b == 1LL) return 0;
    ll t, d = 1, k = 0;
    while ((t = __gcd(a, p)) != 1)
    {
        if (b % t) return -1;
        ++k, b /= t, p /= t, d = d * (a / t) % p;
        if (b == d) return k;
    }
    map<ll, ll> dic;
    ll m = ceil(sqrt(p));
    ll a_m = Pow(a, m, p), mul = b;
    for (ll j = 1; j <= m; ++j) mul = mul * a % p, dic[mul] = j;
    for (ll i = 1; i <= m; ++i)
    {
        d = d * a_m % p;
        if (dic[d]) return i * m - dic[d] + k;
    }
    return -1;
}

ll exgcd(ll a, ll b, ll& x, ll& y)
{
    ll d = a;
    if (b)
        d = exgcd(b, a % b, y, x), y -= x * (a / b);
    else
        x = 1, y = 0;
    return d;
}

ll solve(ll a, ll b, ll m)
{
    if (b == 0) return 0;
    ll d = __gcd(a, m);
    if (b % d) return -1;
    a /= d, b /= d, m /= d;
    ll x, y;
    d = exgcd(a, m, x, y);
    assert(d == 1);
    x = x * b % m;
    return (x + m) % m;
}

int main()
{
    int k;
    scanf("%d", &k);
    mat tr(k, vec(k));
    for (int i = 0; i < k; i++) scanf("%lld", &tr[0][i]);
    for (int i = 1; i < k; i++) tr[i][i - 1] = 1;
    int n, m;
    scanf("%d%d", &n, &m);
    tr = Pow(tr, n - k, mod - 1);
    ll d = exbsgs(3, m, mod);
    ll ans = solve(tr[0][0], d, mod - 1);
    if (~ans)
        printf("%lld\n", Pow(3, ans, mod));
    else
        puts("-1");
}