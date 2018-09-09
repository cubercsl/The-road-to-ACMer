#include <bits/stdc++.h>
using namespace std;

#define lson o << 1
#define rson o << 1 | 1
#define Lson l, m, lson
#define Rson m + 1, r, rson

typedef long long ll;

const int N = 1 << 17;
ll a[N], b[N];

void update(int x, ll v, ll* bit)
{
    for (; x < N; x += x & -x)
        bit[x] += v;
}

ll query(int x, ll* bit)
{
    ll t = 0;
    for (; x; x -= x & -x)
        t += bit[x];
    return t;
}

ll d[N];

int main()
{
    int n, q;
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &d[i]);
        update(i, d[i], a);
        update(i, d[i] * (n - i + 1), b);
    }
    while (q--)
    {
        static int op, a, b;
        scanf("%d%d%d", &op, &a, &b);
        if (op == 2)
        {
            ll delta = b - d[a];
            d[a] = b;
            update(a, delta, ::a);
            update(a, delta * (n - a + 1), ::b);
        }
        else
        {
            ll ans1 = query(b, ::a) - query(a - 1, ::a);
            ll ans2 = query(b, ::b) - query(a - 1, ::b);
            ll x = n - b;
            printf("%lld\n", ans2 - ans1 * x);
        }
    }
}