#include <bits/stdc++.h>
using namespace std;
#define lson (rt << 1)
#define rson (rt << 1 | 1)
const int maxn = 3e5 + 5;
bool vis[maxn];
vector<int> G[maxn];
int a[maxn], col[maxn << 2], lazy[maxn << 2];

inline void pushdown(int rt)
{
    if (!lazy[rt]) return;
    col[lson] = col[rson] = lazy[rt];
    lazy[lson] = lazy[rson] = lazy[rt];
    lazy[rt] = 0;
}
void update(int l, int r, int rt, int L, int R, int x)
{
    if (L <= l && r <= R)
    {
        col[rt] = x;
        lazy[rt] = x;
        return;
    }
    pushdown(rt);
    int m = l + r >> 1;
    if (L <= m) update(l, m, lson, L, R, x);
    if (m + 1 <= R) update(m + 1, r, rson, L, R, x);
}
int query(int l, int r, int rt, int p)
{
    if (l == r) return col[rt];
    pushdown(rt);
    int m = l + r >> 1;
    if (p <= m)
        return query(l, m, lson, p);
    else
        return query(m + 1, r, rson, p);
}
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", a + i);
        vis[a[i]] = 1;
        G[a[i]].push_back(i);
    }
    int m;
    scanf("%d", &m);
    while (m--)
    {
        int x;
        scanf("%d", &x);
        if (!vis[x]) continue;
        vis[x] = 0;
        int l = -1, r = -1;
        for (auto& v : G[x])
        {
            if (query(1, n, 1, v)) continue;
            if (l == -1)
                l = v;
            else
                r = v;
        }
        if (l == -1 || r == -1) continue;   
        update(1, n, 1, l, r, x);
    }
    for (int i = 1; i <= n; i++){
        int x = query(1, n, 1, i);
        printf("%d ", x ? x : a[i]);
    }
}