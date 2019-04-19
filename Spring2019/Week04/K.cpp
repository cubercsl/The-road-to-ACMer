#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1 << 19;
struct Segment_Tree
{

    bool rev = false;

    void init(bool rev)
    {
        this->rev = rev;
    }

    inline int lson(int x) { return x << 1; }
    inline int rson(int x) { return x << 1 | 1; }

    struct Node
    {
        int L, R, M, T, C;
        ll S;
    } nd[maxn << 2];

    inline void pushup(int u)
    {
        if (rev)
            nd[u].M = min(nd[lson(u)].M, nd[rson(u)].M);
        else
            nd[u].M = max(nd[lson(u)].M, nd[rson(u)].M);
        nd[u].S = nd[lson(u)].S + nd[rson(u)].S;
        nd[u].C = nd[lson(u)].C + nd[rson(u)].C;
    }

    inline void maintain(int u, int alter)
    {
        if (rev)
        {
            if (nd[u].T != 0 && nd[u].T >= alter) return;
        }
        else
        {
            if (nd[u].T != 0 && nd[u].T <= alter) return;
        }
        nd[u].T = alter;
        if (nd[u].C != nd[u].R - nd[u].L + 1)
        {
            nd[u].M = alter;
            nd[u].S += 1LL * (nd[u].R - nd[u].L + 1 - nd[u].C) * alter;
            nd[u].C = nd[u].R - nd[u].L + 1;
        }
    }

    void dfs(int u, int alter)
    {
        if (rev)
        {

            if (nd[u].M >= alter) return;
        }
        else
        {
            if (nd[u].M <= alter) return;
        }

        nd[u].T = 0;
        if (nd[u].L == nd[u].R)
        {
            nd[u].S = nd[u].M = nd[u].C = 0;
            return;
        }
        dfs(lson(u), alter);
        dfs(rson(u), alter);
        pushup(u);
    }

    inline void pushdown(int u)
    {
        if (nd[u].T == 0) return;
        maintain(lson(u), nd[u].T);
        maintain(rson(u), nd[u].T);
    }

    void build(int u, int l, int r)
    {
        nd[u].L = l, nd[u].R = r, nd[u].T = 0;
        if (l == r)
        {
            nd[u].M = l;
            nd[u].T = nd[u].S = nd[u].M;
            nd[u].C = 1;
            return;
        }

        int mid = (l + r) >> 1;
        build(lson(u), l, mid);
        build(rson(u), mid + 1, r);
        pushup(u);
    }

    void modify(int u, int l, int r, int alter)
    {
        if (rev)
        {
            if (nd[u].M >= alter)
                return;
        }
        else
        {
            if (nd[u].M <= alter)
                return;
        }

        if (l <= nd[u].L && nd[u].R <= r)
        {
            dfs(u, alter);
            maintain(u, alter);
            return;
        }

        int mid = (nd[u].L + nd[u].R) >> 1;
        pushdown(u);
        if (l <= mid)
            modify(lson(u), l, r, alter);
        if (r > mid)
            modify(rson(u), l, r, alter);
        pushup(u);
    }

    void query(int u, int l, int r, ll& sum)
    {
        if (l <= nd[u].L && nd[u].R <= r)
        {
            sum = sum + nd[u].S;
            return;
        }

        int mid = (nd[u].L + nd[u].R) >> 1;
        pushdown(u);
        if (l <= mid)
            query(lson(u), l, r, sum);
        if (r > mid)
            query(rson(u), l, r, sum);
        pushup(u);
    }
} t1, t2;

int main()
{
    int n, m;
    while (~scanf("%d%d", &n, &m))
    {
        t1.init(false);
        t2.init(true);
        t1.build(1, 1, n);
        t2.build(1, 1, n);
        ll last = 0;
        for (int i = 0, l, r; i < m; i++)
        {
            scanf("%d%d", &l, &r);
            t1.modify(1, l, r, l);
            t2.modify(1, l, r, r);
            ll sum1 = 0, sum2 = 0;
            t1.query(1, 1, n, sum1);
            t2.query(1, 1, n, sum2);
       
            ll ans = sum2 - sum1;
            printf("%lld\n", (ans - last) / 2);
            last = ans;
        }
    }
}