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

#define lson rt << 1
#define rson rt << 1 | 1
#define Lson l, mid, lson
#define Rson mid + 1, r, rson

const int N = 3e5 + 5;
ll sum[N << 2];
bool f[N << 2];

const int maxn = 1e6 + 5;
int d[maxn];
void init(int n)
{
    for (int i = 1; i < n; i++)
        for (int j = i; j < n; j += i)
            d[j]++;
}

inline void pushup(int rt)
{
    sum[rt] = sum[lson] + sum[rson];
    f[rt] = f[lson] & f[rson];
}

void build(int l, int r, int rt)
{
    if (l == r)
    {
        scanf("%lld", &sum[rt]);
        f[rt] = sum[rt] <= 2;
        return;
    }
    int mid = l + r >> 1;
    build(Lson);
    build(Rson);
    pushup(rt);
}

ll query(int L, int R, int l, int r, int rt)
{
    if (L <= l && r <= R) return sum[rt];
    int mid = l + r >> 1;
    ll s = 0;
    if (L <= mid) s += query(L, R, Lson);
    if (mid < R) s += query(L, R, Rson);
    return s;
}

void update(int L, int R, int l, int r, int rt)
{
    if (f[rt]) return;
    if (l == r)
    {
        sum[rt] = d[sum[rt]];
        f[rt] = sum[rt] <= 2;
        return;
    }
    int mid = l + r >> 1;
    if (L <= mid) update(L, R, Lson);
    if (mid < R) update(L, R, Rson);
    pushup(rt);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    init(1e6 + 5);
    int n, m;
    scanf("%d%d", &n, &m);
    build(1, n, 1);
    while (m--)
    {
        static int t, l, r;
        scanf("%d%d%d", &t, &l, &r);
        if (t == 1)
            update(l, r, 1, n, 1);
        else
            printf("%lld\n", query(l, r, 1, n, 1));
    }
    return 0;
}
