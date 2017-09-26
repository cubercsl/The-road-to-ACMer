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

const int maxn = 1e5 + 5;
int val[maxn << 2];

void build(int l, int r, int rt)
{
    if (l == r)
    {
        scanf("%d", &val[rt]);
        return;
    }
    int m = (l + r) >> 1;
    build(Lson);
    build(Rson);
    val[rt] = __gcd(val[lson], val[rson]);
}

int query(int L, int R, int l, int r, int rt)
{
    if (L <= l && r <= R)
        return val[rt];
    int m = (l + r) >> 1;
    int ret = 0;
    if (L <= m) ret = __gcd(query(L, R, Lson), ret);
    if (m < R) ret = __gcd(query(L, R, Rson), ret);
    return ret;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n, q;
    while (~scanf("%d%d", &n, &q))
    {
        build(1, n, 1);
        while (q--)
        {
            int l, r;
            scanf("%d%d", &l, &r);
            printf("%d\n", query(l, r, 1, n, 1));
        }
    }
    return 0;
}
