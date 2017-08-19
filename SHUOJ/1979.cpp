#include <bits/stdc++.h>
using namespace std;
#define clr(a,x) memset(a, x, sizeof(a))
#define mp(x,y) make_pair(x,y)
#define pb(x) push_back(x)
#define X first
#define Y second
#define fastin ios_base::sync_with_stdio(0);cin.tie(0);
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

const int maxn = 2e5 + 5;
int maxv[maxn << 2], addv[maxn << 2];

void pushup(int rt)
{
    maxv[rt] = max(maxv[lson], maxv[rson]);
}

void pushdown(int rt)
{
    if (addv[rt] == 0) return;
    addv[lson] += addv[rt];
    addv[rson] += addv[rt];
    maxv[lson] += addv[rt];
    maxv[rson] += addv[rt];
    addv[rt] = 0;
}

void build(int l, int r, int rt)
{
    maxv[rt] = addv[rt] = 0;
    if (l == r) return;
    int m = (l + r) >> 1;
    build(Lson);
    build(Rson);
}

void update(int L, int R , int add, int l, int r, int rt)
{
    if (L <= l && r <= R)
    {
        addv[rt] += add;
        maxv[rt] += add;
        return;
    }
    pushdown(rt);
    int m = (l + r) >> 1;
    if (L <= m) update(L, R, add, Lson);
    if (m < R) update(L, R, add, Rson);
    pushup(rt);
}

int query(int L, int R, int l, int r, int rt)
{
    if (L <= l && r <= R) return maxv[rt];
    pushdown(rt);
    int m = (l + r) >> 1, ans = 0;
    if (L <= m) ans = max(ans, query(L, R, Lson));
    if (m < R) ans = max(ans, query(L, R, Rson));
    return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n, m, k;
    while (~scanf("%d%d%d", &n, &m, &k))
    {
        n <<= 1;
        build(1, n, 1);
        while (m--)
        {
            int l, r;
            scanf("%d%d", &l, &r);
            l <<= 1, r--, r <<= 1;
            if (query(l, r, 1, n, 1) < k)
            {
                puts("Yes");
                update(l, r, 1, 1, n, 1);
            }
            else
                puts("No");
        }
    }
    return 0;
}
