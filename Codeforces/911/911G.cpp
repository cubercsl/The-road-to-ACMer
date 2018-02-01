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

int n;
struct state
{
    int a[101];
};
int raw[maxn];
state a[maxn << 2];
void init(int L = 0, int R = n, int o = 1)
{
    for (int i = 1; i <= 100; i++)
    {
        a[o].a[i] = i;
    }
    if (L + 1 == R)
    {
        return;
    }
    const int mid = (L + R) >> 1;
    init(L, mid, o << 1);
    init(mid, R, o << 1 | 1);
}
void pushdown(int r)
{
    for (int i = 1; i <= 100; i++)
    {
        a[r << 1].a[i] = a[r].a[a[r << 1].a[i]];
        a[r << 1 | 1].a[i] = a[r].a[a[r << 1 | 1].a[i]];
    }
    for (int i = 1; i <= 100; i++)
    {
        a[r].a[i] = i;
    }
}

void add(int x, int y, int ql, int qr, int L = 0, int R = n, int o = 1)
{
    if (ql <= L && R <= qr)
    {
        for (int i = 1; i <= 100; i++)
        {
            if (a[o].a[i] == x)
            {
                a[o].a[i] = y;
            }
        }
        return;
    }
    pushdown(o);
    const int mid = (L + R) >> 1;
    if (ql < mid) add(x, y, ql, qr, L, mid, o << 1);
    if (mid < qr) add(x, y, ql, qr, mid, R, o << 1 | 1);
}

void dfs(int L = 0, int R = n, int o = 1)
{
    if (L + 1 == R)
    {
        raw[L] = a[o].a[raw[L]];
        return;
    }
    pushdown(o);
    const int mid = (L + R) >> 1;
    dfs(L, mid, o << 1);
    dfs(mid, R, o << 1 | 1);
}

int q;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    while (~scanf("%d", &n))
    {
        init();
        for (int i = 0; i < n; i++)
        {
            scanf("%d", raw + i);
        }
        scanf("%d", &q);
        while (q--)
        {
            int l, r, x, y;
            scanf("%d%d%d%d", &l, &r, &x, &y);
            add(x, y, l - 1, r);
        }
        dfs();
        for (int i = 0; i < n; i++)
        {
            printf("%d%c", raw[i], i == (n - 1) ? '\n' : ' ');
        }
    }
    return 0;
}
