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

const int N = 1 << 18;
int a[N];
int num[N << 2][105];
void build(int l, int r, int rt)
{
    for (int i = 1; i <= 100; i++) num[rt][i] = i;
    if (l == r) return;
    int m = (l + r) >> 1;
    build(Lson);
    build(Rson);
}

void pushdown(int rt)
{
    for (int i = 1; i <= 100; i++)
    {
        num[lson][i] = num[rt][num[lson][i]];
        num[rson][i] = num[rt][num[rson][i]];
    }
    for (int i = 1; i <= 100; i++)
        num[rt][i] = i;
}

void update(int L, int R, int x, int y, int l, int r, int rt)
{
    if (L <= l && r <= R)
    {
        for (int i = 1; i <= 100; i++)
            if (num[rt][i] == x) num[rt][i] = y;
        return;
    }
    pushdown(rt);
    int m = (l + r) >> 1;
    if (L <= m) update(L, R, x, y, Lson);
    if (m < R) update(L, R, x, y, Rson);
}

void query(int l, int r, int rt)
{
    if (l == r)
    {
        a[l] = num[rt][a[l]];
        return;
    }
    pushdown(rt);
    int m = (l + r) >> 1;
    query(Lson);
    query(Rson);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n, q;
    while (~scanf("%d", &n))
    {
        build(1, n, 1);
        for (int i = 1; i <= n; i++) scanf("%d", a + i);
        scanf("%d", &q);
        while (q--)
        {
            static int l, r, x, y;
            scanf("%d%d%d%d", &l, &r, &x, &y);
            update(l, r, x, y, 1, n, 1);
        }
        query(1, n, 1);
        for (int i = 1; i <= n; i++) printf("%d%c", a[i], i == n ? '\n' : ' ');
    }
    return 0;
}
