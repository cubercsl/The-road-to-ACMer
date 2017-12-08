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
#define Lson l, m, lson
#define Rson m + 1, r, rson

const int N = 50005;
int sum[N << 2], tag[N << 2];

inline void pushup(int rt) { sum[rt] = sum[lson] + sum[rson]; }

inline void pushdown(int rt, int m)
{
    int& x = tag[rt];
    if (!x) return;
    sum[lson] = ~x ? 0 : m - (m >> 1);
    sum[rson] = ~x ? 0 : (m >> 1);
    tag[lson] = tag[rson] = x;
    x = 0;
}

void build(int l, int r, int rt)
{
    tag[rt] = 0;
    if (l == r)
    {
        sum[rt] = 1;
        return;
    }
    int m = (l + r) >> 1;
    build(Lson);
    build(Rson);
    pushup(rt);
}

void update(int L, int R, int v, int l, int r, int rt)
{ // v = -1 clear
    if (L <= l && r <= R)
    {
        sum[rt] = ~v ? 0 : (r - l + 1);
        tag[rt] = v;
        return;
    }
    pushdown(rt, r - l + 1);
    int m = (l + r) >> 1;
    if (L <= m) update(L, R, v, Lson);
    if (m < R) update(L, R, v, Rson);
    pushup(rt);
}

int query(int L, int R, int l, int r, int rt)
{
    if (L <= l && r <= R) return sum[rt];
    pushdown(rt, r - l + 1);
    int m = (l + r) >> 1;
    int ret = 0;
    if (L <= m) ret += query(L, R, Lson);
    if (m < R) ret += query(L, R, Rson);
    return ret;
}

void solve(int l, int r, int f, const int& n)
{
    int x = query(l, r, 0, n - 1, 1);
    if (x == 0)
    {
        puts("Can not put any one.");
        return;
    }
    f = min(f, x);
    int L = l, R = r, LL, RR;
    while (L <= R)
    {
        int mid = (L + R) >> 1;
        if (query(L, mid, 0, n - 1, 1))
            R = mid - 1, LL = mid;
        else
            L = mid + 1;
    }
    printf("%d ", LL);
    L = l, R = r;
    while (L <= R)
    {
        int mid = (L + R) >> 1;
        x = query(L, mid, 0, n - 1, 1);
        if (x >= f)
            R = mid - 1, RR = mid;
        else
            L = mid + 1, f -= x;
    }
    printf("%d\n", RR);
    update(LL, RR, 1, 0, n - 1, 1);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n, q;
        scanf("%d%d", &n, &q);
        build(0, n - 1, 1);
        while (q--)
        {
            static int op, a, b;
            scanf("%d%d%d", &op, &a, &b);
            if (op == 1)
                solve(a, n - 1, b, n);
            else
            {
                int tmp = query(a, b, 0, n - 1, 1);
                printf("%d\n", b - a + 1 - tmp);
                update(a, b, -1, 0, n - 1, 1);
            }
        }
        puts("");
    }
    return 0;
}
