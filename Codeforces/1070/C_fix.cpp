#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#define dbg(args...)                             \
    do                                           \
    {                                            \
        cout << "\033[32;1m" << #args << " -> "; \
        err(args);                               \
    } while (0)
#else
#define dbg(...)
#endif
void err()
{
    cout << "\033[39;0m" << endl;
}
template <template <typename...> class T, typename t, typename... Args>
void err(T<t> a, Args... args)
{
    for (auto x : a) cout << x << ' ';
    err(args...);
}
template <typename T, typename... Args>
void err(T a, Args... args)
{
    cout << a << ' ';
    err(args...);
}
/****************************************************************************************************/

struct Node
{
    int l, r, c, p;
    bool operator<(const Node& A) const
    {
        if (p == A.p) return c > A.c;
        return p < A.p;
    }
};
typedef long long ll;
const int N = 1 << 20;
ll sum[N << 2], maxv[N << 2], minv[N << 2];
ll setv[N << 2], subv[N << 2];
Node a[N];

#define lson o << 1
#define rson o << 1 | 1
#define Lson l, m, lson
#define Rson m + 1, r, rson

void pushup(int o)
{
    sum[o] = sum[lson] + sum[rson];
    maxv[o] = max(maxv[lson], maxv[rson]);
    minv[o] = max(minv[lson], minv[rson]);
}

void pushdown(int o, int m)
{
    if (setv[o])
    {
        sum[lson] = maxv[lson] = minv[lson] = 0;
        sum[rson] = maxv[rson] = minv[rson] = 0;
        setv[o] = 0;
    }
    else
    {
        if (!subv[o]) return;
        sum[lson] -= subv[o] * m;
        maxv[lson] -= subv[o];
        minv[lson] -= subv[o];
        sum[rson] -= subv[o] * m;
        maxv[rson] -= subv[o];
        minv[rson] -= subv[o];
        subv[o] = 0;
    }
}

void build(int l, int r, int o, int v)
{
    if (l == r)
    {
        sum[o] = maxv[o] = minv[o] = v;
        return;
    }
    const int m = l + r >> 1;
    build(Lson, v), build(Rson, v);
    pushup(o);
}

ll update(int L, int R, int x, int p, int l, int r, int o)
{
    ll ret = 0;
    const int m = l + r >> 1;
    if (L <= l && r <= R)
    {
        if (x >= maxv[o])
        {
            ret += sum[o] * p;
            sum[o] = maxv[o] = minv[o] = 0;
            setv[o] = 1;
            pushup(o);
            return ret;
        }
        if (x <= minv[o])
        {
            ret += x * (r - l + 1) * p;
            subv[o] += x;
            sum[o] -= x * (r - l + 1);
            maxv[o] -= x;
            minv[o] -= x;
            pushup(o);

            return ret;
        }
    }
    pushdown(o, r - l + 1);
    if (L <= m)
        ret += update(L, R, x, p, Lson);
    if (m + 1 <= R)
        ret += update(L, R, x, p, Rson);
    pushup(o);
    return ret;
}

int main()
{
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < k; i++)
    {
        scanf("%d%d%d%d", &a[i].l, &a[i].r, &a[i].c, &a[i].p);
    }
    sort(a, a + k);
    build(1, n, 1, m);
    ll ans = 0;
    for (int i = 0; i < k; i++)
        ans += update(a[i].l, a[i].r, a[i].c, a[i].p, 1, n, 1);
    printf("%lld\n", ans);
    return 0;
}