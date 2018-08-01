#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int p = 1e9 + 7;
const int maxn = 1 << 17;
ll Pow(ll a, ll n, ll p)
{
    ll t = 1;
    for (; n; n >>= 1, (a *= a) %= p)
        if (n & 1) (t *= a) %= p;
    return t;
}
ll f[maxn];
ll inv[maxn];
void init()
{
    f[0] = 1;
    for (int i = 1; i < maxn; i++) f[i] = (f[i - 1] * i) % p;
    inv[maxn - 1] = Pow(f[maxn - 1], p - 2, p);
    for (int i = maxn - 2; ~i; i--) inv[i] = inv[i + 1] * (i + 1) % p;
}
ll C(int n, int m) { return f[n] * inv[m] % p * inv[n - m] % p; }

const int unit = 333;
struct query
{
    int l, r;
    int id;
    query(int x = 0, int y = 0, int id = 0) : l(x), r(y), id(id) {}
};

int main()
{
    init();
    int q;
    ll inv2 = Pow(2, p - 2, p);
    scanf("%d", &q);
    vector<query> v;
    for (int i = 0; i < q; i++)
    {
        static int n, m;
        scanf("%d%d", &n, &m);
        v.emplace_back(n, m, i);
    }
    vector<int> ans(q);
    sort(v.begin(), v.end(), [](query a, query b) { return a.l / unit < b.l / unit || a.l / unit == b.l / unit && a.r < b.r; });
    int L = 1, R = 0;
    long long tmp = 1;
    for (auto& t : v)
    {
        while (t.l < L)
        {
            --L;
            tmp = ((tmp + C(L, R)) * inv2) % p;
        }
        //  add(a[--L]);
        while (t.l > L)
        {
            tmp = (tmp * 2 % p - C(L, R) + p) % p;
            L++;
        }
        //  del(a[L++]);
        while (t.r < R)
        {
            tmp = (tmp - C(L, R) + p) % p;
            R--;
        }
        // del(a[R--]);
        while (t.r > R)
        {
            ++R;
            tmp = (tmp + C(L, R)) % p;
        }
        // add(a[++R]);
        ans[t.id] = tmp;
    }
    for (auto& t : ans) printf("%d\n", t);
}