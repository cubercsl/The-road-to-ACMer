#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const static int N = 1 << 19;
const static int mod = 1e9 + 7;
vector<int> p, invp;
ll Pow(ll a, ll n)
{
    ll t = 1;
    for (; n; n >>= 1, (a *= a) %= mod)
        if (n & 1) (t *= a) %= mod;
    return t;
}
inline bool isprime(int n)
{
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) return false;
    return n != 1;
}
void init(int n)
{
    for (int i = 2; i <= n; i++)
        if (isprime(i)) p.push_back(i);
    for (auto t : p)
        invp.push_back(Pow(t, mod - 2));
}
ll gao(int x)
{
    ll ret = 0;
    for (int i = 0; i < p.size(); i++)
        if (x % p[i] == 0) ret |= (1LL << i);
    return ret;
}
namespace Segment_Tree
{
typedef long long type_t;
type_t pro[N << 2], bit[N << 2];
type_t mul[N << 2], tag[N << 2];
#define lson o << 1
#define rson o << 1 | 1
#define Lson l, m, lson
#define Rson m + 1, r, rson
inline void pushup(int o)
{
    pro[o] = (pro[lson] * pro[rson]) % mod;
    bit[o] = (bit[lson] | bit[rson]);
}
inline void pushdown(int o, int m)
{
    if (mul[o] != 1)
    {
        (mul[lson] *= mul[o]) %= mod;
        (mul[rson] *= mul[o]) %= mod;
        (pro[lson] *= Pow(mul[o], m - (m >> 1))) %= mod;
        (pro[rson] *= Pow(mul[o], m >> 1)) %= mod;
        mul[o] = 1;
    }
    if (tag[o] != 0)
    {
        tag[lson] |= tag[o];
        tag[rson] |= tag[o];
        bit[lson] |= tag[o];
        bit[rson] |= tag[o];
        tag[o] = 0;
    }
}
void build(int l = 1, int r = N, int o = 1)
{
    mul[o] = 1, tag[o] = 0;
    if (l == r)
    {
        scanf("%lld", &pro[o]);
        bit[o] = gao(pro[o]);
        return;
    }
    const int m = l + r >> 1;
    build(Lson);
    build(Rson);
    pushup(o);
}
void update(int L, int R, pair<type_t, type_t> v, int l = 1, int r = N, int o = 1)
{
    if (L <= l && r <= R)
    {
        (mul[o] *= v.first) %= mod;
        (pro[o] *= Pow(v.first, r - l + 1)) %= mod;
        tag[o] |= v.second;
        bit[o] |= v.second;
        return;
    }
    pushdown(o, r - l + 1);
    const int m = l + r >> 1;
    if (L <= m) update(L, R, v, Lson);
    if (m < R) update(L, R, v, Rson);
    pushup(o);
}
pair<type_t, type_t>& operator|=(pair<type_t, type_t>& a, const pair<type_t, type_t>& b)
{
    (a.first *= b.first) %= mod;
    a.second |= b.second;
}
pair<type_t, type_t> query(int L, int R, int l = 1, int r = N, int o = 1)
{
    if (L <= l && r <= R) return make_pair(pro[o], bit[o]);
    pushdown(o, r - l + 1);
    const int m = l + r >> 1;
    pair<type_t, type_t> ret = make_pair(1, 0);
    if (L <= m) ret |= query(L, R, Lson);
    if (m < R) ret |= query(L, R, Rson);
    return ret;
}
#undef lson
#undef rson
#undef Lson
#undef Rson
}; // namespace Segment_Tree
int main()
{
    init(300);
    int n, q;
    scanf("%d%d", &n, &q);
    Segment_Tree::build(1, n, 1);
    for (int i = 0, l, r, x; i < q; i++)
    {
        static char op[10];
        scanf("%s%d%d", op, &l, &r);
        long long prod, bit;
        if (op[0] == 'T')
        {
            tie(prod, bit) = Segment_Tree::query(l, r, 1, n, 1);
            for (int i = 0; i < p.size(); i++)
                if (bit >> i & 1) prod = prod * (p[i] - 1) % mod * invp[i] % mod;
            printf("%lld\n", prod);
        }
        else
        {
            scanf("%d", &x);
            prod = x, bit = 0;
            for (int i = 0; i < p.size(); i++)
                if (x % p[i] == 0) bit |= 1LL << i;
            Segment_Tree::update(l, r, make_pair(prod, bit), 1, n, 1);
        }
    }
}