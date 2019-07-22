#include <bits/stdc++.h>
using namespace std;

typedef unsigned int uint32;

struct Bitset
{
    uint32 data[8];
    void clear() { memset(data, 0, sizeof(data)); }
    void flip(int x) { data[x >> 5] ^= 1U << (x & 31); }
    void set(int x) { data[x >> 5] |= 1U << (x & 31); }
    void reset(int x) { data[x >> 5] &= ~(1U << (x & 31)); }
    int get(int x) { return data[x >> 5] >> (x & 31) & 1; }
};

const int N = 256;
Bitset g[N], rg[N];
char buf[N];
Bitset vis;
int belong[N];
int num;
int cnt1, cnt2;
int st[N];
void dfs1(int u)
{
    vis.flip(u);
    for (int i = 0; i < 8; i++)
    {
        for (;;)
        {
            uint32 o = vis.data[i] & g[u].data[i];
            if (!o) break;
            dfs1(i << 5 | __builtin_ctz(o));
        }
    }
    st[cnt1++] = u;
}

void dfs2(int u)
{
    vis.flip(u);
    num++;
    for (int i = 0; i < 8; i++)
    {
        for (;;)
        {
            uint32 o = vis.data[i] & rg[u].data[i];
            if (!o) break;
            dfs2(i << 5 | __builtin_ctz(o));
        }
    }
}

void solve(int n)
{
    vis.clear();
    for (int i = 0; i < n; i++) vis.set(i);
    long long ans = 0;
    cnt1 = cnt2 = 0;
    for (int i = 0; i < n; i++)
        if (vis.get(i)) dfs1(i);
    vis.clear();
    for (int i = 0; i < n; i++) vis.set(i);
    for (int i = cnt1 - 1; ~i; i--)
        if (vis.get(st[i]))
        {
            num = 0;
            dfs2(st[i]);
            ans = ans + num * (num - 1) / 2;
        }
    printf("%lld\n", ans);
}

void flip(int u, int v)
{
    g[u].flip(v);
    rg[v].flip(u);
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n, q;
        scanf("%d%d", &n, &q);
        for (int i = 0; i < n; i++) g[i].clear(), rg[i].clear();
        for (int i = 0; i < n; i++)
        {
            scanf("%s", buf);
            for (int j = 0; j < n; j++)
                if (buf[j] - '0')
                    g[i].set(j), rg[j].set(i);
        }
        for (int i = 0; i < q; i++)
        {
            int k;
            scanf("%d", &k);
            for (int j = 0, u, v; j < k; j++)
            {
                scanf("%d%d", &u, &v);
                flip(u - 1, v - 1);
            }
            solve(n);
        }
    }
}