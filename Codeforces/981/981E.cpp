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

const int N = 1 << 14;
vector<int> T[N << 2];

void update(int L, int R, int x, int l, int r, int rt)
{
    if (L <= l && r <= R)
    {
        T[rt].push_back(x);
        return;
    }
    int m = l + r >> 1;
    if (L <= m)
        update(L, R, x, Lson);
    if (m < R)
        update(L, R, x, Rson);
}

bitset<N> bst[16], ans;
void gao(int l, int r, int rt, int dep)
{
    bst[dep] = bst[dep - 1];
    if (l == r)
    {
        for (auto& v : T[rt]) bst[dep] |= (bst[dep] << v);
        ans |= bst[dep];
        return;
    }
    for (auto& v : T[rt]) bst[dep] |= (bst[dep] << v);
    int m = l + r >> 1;
    gao(Lson, dep + 1);
    gao(Rson, dep + 1);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    bst[0][0] = 1;
    int n, q;
    scanf("%d%d", &n, &q);
    for (int i = 0, l, r, x; i < q; i++)
    {
        scanf("%d%d%d", &l, &r, &x);
        update(l, r, x, 1, n, 1);
    }
    gao(1, n, 1, 1);
    int ret = 0;
    for (int i = 1; i <= n; i++) ret += ans[i];
    printf("%d\n", ret);
    for (int i = 1; i <= n; i++)
        if (ans[i]) printf("%d ", i);
    return 0;
}