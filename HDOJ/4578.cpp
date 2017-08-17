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
const int mod = 1e4 + 7;
const double eps = 1e-6;

#define lson rt << 1
#define rson rt << 1 | 1
#define Lson l, m, lson
#define Rson m + 1, r, rson
#define lm (m - (m >> 1))
#define rm (m >> 1)

const int maxn = 1e5 + 5;
int sum[maxn << 2], quad[maxn << 2], cube[maxn << 2];   // 维护区间和，平方和，立方和
int addv[maxn << 2], mulv[maxn << 2], setv[maxn << 2];  // 三种操作的延迟更新标记

void build(int l, int r, int rt)
{
    sum[rt] = quad[rt] = cube[rt] = 0;
    setv[rt] = addv[rt] = 0;
    mulv[rt] = 1;
    if (l == r) return;
    int m = (l + r) >> 1;
    build(Lson);
    build(Rson);
}

void pushup(int rt)
{
    sum[rt] = (sum[lson] + sum[rson]) % mod;
    quad[rt] = (quad[lson] + quad[rson]) % mod;
    cube[rt] = (cube[lson] + cube[rson]) % mod;
}

void pushdown(int rt, int m)
{
    if (setv[rt] != 0)
    {
        setv[lson] = setv[rson] = setv[rt];
        addv[lson] = addv[rson] = 0;
        mulv[lson] = mulv[rson] = 1;
        sum[lson] = setv[rt] * lm % mod;
        sum[rson] = setv[rt] * rm % mod;
        quad[lson] = setv[rt] * lm % mod * setv[rt] % mod;
        quad[rson] = setv[rt] * rm  % mod * setv[rt] % mod;
        cube[lson] = setv[rt] * lm % mod * setv[rt] % mod * setv[rt] % mod;
        cube[rson] = setv[rt] * rm  % mod * setv[rt] % mod * setv[rt] % mod;
        setv[rt] = 0;
    }
    if (addv[rt] != 0 || mulv[rt] != 1)
    {
        addv[lson] = (mulv[rt] * addv[lson] % mod + addv[rt]) % mod;
        addv[rson] = (mulv[rt] * addv[rson] % mod + addv[rt]) % mod;
        mulv[lson] = mulv[lson] * mulv[rt] % mod;
        mulv[rson] = mulv[rson] * mulv[rt] % mod;
        cube[lson] = (mulv[rt] * mulv[rt] % mod * mulv[rt] % mod * cube[lson] % mod
                      + 3 * mulv[rt] * mulv[rt] % mod * quad[lson] % mod * addv[rt] % mod
                      + 3 * mulv[rt] * sum[lson] % mod * addv[rt] % mod * addv[rt] % mod
                      + lm * addv[rt] % mod * addv[rt] % mod * addv[rt] % mod) % mod;
        cube[rson] = (mulv[rt] * mulv[rt] % mod * mulv[rt] % mod * cube[rson] % mod
                      + 3 * mulv[rt] * mulv[rt] % mod * quad[rson] % mod * addv[rt] % mod
                      + 3 * mulv[rt] * sum[rson] % mod * addv[rt] % mod * addv[rt] % mod
                      + rm * addv[rt] % mod * addv[rt] % mod * addv[rt] % mod) % mod;
        quad[lson] = (mulv[rt] * mulv[rt] % mod * quad[lson] % mod
                      + 2 * mulv[rt] * sum[lson] % mod * addv[rt] % mod
                      + lm * addv[rt] % mod * addv[rt] % mod) % mod;
        quad[rson] = (mulv[rt] * mulv[rt] % mod * quad[rson] % mod
                      + 2 * mulv[rt] * sum[rson] % mod * addv[rt] % mod
                      + rm * addv[rt] % mod * addv[rt] % mod) % mod;
        sum[lson] = (mulv[rt] * sum[lson] % mod + lm * addv[rt] % mod) % mod;
        sum[rson] = (mulv[rt] * sum[rson] % mod + rm * addv[rt] % mod) % mod;
        addv[rt] = 0;
        mulv[rt] = 1;
    }
}

void update(int L, int R, int type, int c, int l, int r, int rt)
{
    int len = r - l + 1;
    if (L <= l && r <= R)
    {
        c %= mod;
        if (type == 1)
        {
            addv[rt] = (addv[rt] + c) %  mod;
            cube[rt] = (cube[rt] + 3 * quad[rt] * c % mod +
                        3 * sum[rt] % mod * c % mod * c % mod +
                        len * c % mod * c % mod * c % mod) % mod;
            quad[rt] = (quad[rt] + 2 * sum[rt] * c % mod +
                        len * c % mod * c % mod) % mod;
            sum[rt] = (sum[rt] + len * c % mod) % mod;
        }
        else if (type == 2)
        {
            addv[rt] = addv[rt] * c % mod;
            mulv[rt] = mulv[rt] * c % mod;
            sum[rt] = sum[rt] * c % mod;
            quad[rt] = quad[rt] * c % mod * c % mod;
            cube[rt] = cube[rt] * c % mod * c % mod * c % mod;
        }
        else
        {
            addv[rt] = 0;
            mulv[rt] = 1;
            setv[rt] = c % mod;
            sum[rt] = c * len % mod;
            quad[rt] = c * len % mod * c % mod;
            cube[rt] = c * len % mod * c % mod * c % mod;
        }
        return;
    }
    pushdown(rt, r - l + 1);
    int m = (l + r) >> 1;
    if (L <= m) update(L, R, type, c, Lson);
    if (m < R) update(L, R, type, c, Rson);
    pushup(rt);
}

int query(int L, int R, int p, int l, int r, int rt)
{
    if (L <= l && r <= R)
    {
        if (p == 1)
            return sum[rt];
        if (p == 2)
            return quad[rt];
        if (p == 3)
            return cube[rt];
    }
    pushdown(rt, r - l + 1);
    int m = (l + r) >> 1;
    int ret = 0;
    if (L <= m) ret = (ret + query(L, R, p, Lson)) % mod;
    if (m < R) ret = (ret + query(L, R, p, Rson)) % mod;
    return ret;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n, m;
    while (~scanf("%d%d", &n, &m), n + m)
    {
        build(1, n, 1);
        int x, y, c, type;
        while (m--)
        {
            scanf("%d%d%d%d", &type, &x, &y, &c);
            if (type == 4) printf("%d\n", query(x, y, c, 1, n, 1));
            else update(x, y, type, c, 1, n, 1);
        }
    }
    return 0;
}
