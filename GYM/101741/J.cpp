#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;
const int maxn = 20;
int n, m;
struct Mat
{
    ll m[maxn][maxn];
    void clear()
    {
        memset(m, 0, sizeof(m));
    }
};
Mat operator*(Mat a, Mat b)
{
    Mat c;
    memset(c.m, 0, sizeof(c.m));
    for (int i = 0; i < m; i++)
    {
        for (int k = 0; k < m; k++)
        {
            if (a.m[k][i] == 0) continue;
            for (int p = 0; p < m; p++)
            {
                if (b.m[i][p] == 0) continue;
                c.m[k][p] = (c.m[k][p] + a.m[k][i] * b.m[i][p] % mod) % mod;
            }
        }
    }
    return c;
}

#define lson o << 1
#define rson o << 1 | 1
#define Lson l, m, lson
#define Rson m + 1, r, rson

const int N = 1 << 18;
Mat t[N << 2];

void pushup(int o)
{
    t[o] = t[rson] * t[lson];
}

void build(int l, int r, int o)
{
    if (l == r)
    {
        static int x;
        scanf("%d", &x);
        t[o].clear();
        for (int i = 0; i < m; i++)
            t[o].m[i][(i - x + m) % m] = t[o].m[i][i] = 1;
        return;
    }
    const int m = l + r >> 1;
    build(Lson);
    build(Rson);
    pushup(o);
}

Mat query(int L, int R, int l, int r, int o)
{
    if (L <= l && r <= R) return t[o];
    const int m = l + r >> 1;
    Mat ans;
    ans.clear();
    for (int i = 0; i < ::m; i++) ans.m[i][i] = 1;
    if (L <= m) ans = ans * query(L, R, Lson);
    if (m < R) ans = query(L, R, Rson) * ans;
    return ans;
}

int main()
{
    scanf("%d%d", &n, &m);
    build(1, n, 1);
    int q;
    scanf("%d", &q);
    while (q--)
    {
        static int l, r;
        scanf("%d%d", &l, &r);
        auto ret = query(l, r, 1, n, 1);
        printf("%lld\n", ret.m[0][0]);
    }
    return 0;
}