#include <bits/stdc++.h>
using namespace std;

const int maxn = 1 << 20;
const int mod = 1e9 + 7;
int ans[maxn], p[maxn];

struct SAM
{
    int len[maxn << 1], link[maxn << 1], ch[maxn << 1][26];
    int tag[maxn << 1], val[maxn << 1];
    int sz, rt, last;
    int newnode(int x = 0)
    {
        len[sz] = x;
        link[sz] = -1;
        tag[sz] = -1;
        val[sz] = 1;
        memset(ch[sz], -1, sizeof(ch[sz]));
        return sz++;
    }
    void init() { sz = last = 0, rt = newnode(); }
    void reset() { last = 0; }
    void extend(int c)
    {
        int np = newnode(len[last] + 1);
        int p;
        for (p = last; ~p && ch[p][c] == -1; p = link[p]) ch[p][c] = np;
        if (p == -1)
            link[np] = rt;
        else
        {
            int q = ch[p][c];
            if (len[p] + 1 == len[q])
                link[np] = q;
            else
            {
                int nq = newnode(len[p] + 1);
                memcpy(ch[nq], ch[q], sizeof(ch[q]));
                link[nq] = link[q], link[q] = link[np] = nq;
                for (; ~p && ch[p][c] == q; p = link[p]) ch[p][c] = nq;
            }
        }
        last = np;
    }
    void build(const string& s, int v, int id)
    {
        int u = 0;
        for (auto& c : s)
        {
            u = ch[u][c - 'a'];
            int p = u;
            while (p && tag[p] != id)
            {
                val[p] = 1LL * val[p] * v % mod;
                tag[p] = id;
                p = link[p];
            }
        }
    }
    void build()
    {
        for (int u = 0; u < sz; u++)
        {
            int fa = link[u];
            ans[len[fa] + 1] = (ans[len[fa] + 1] + val[u]) % mod;
            ans[len[u] + 1] = (ans[len[u] + 1] - val[u] + mod) % mod;
        }
    }
} sam;

string s[maxn];
char buf[maxn];
int val[maxn];

int Pow(int a, int n)
{
    int t = 1;
    for (; n; n >>= 1, a = 1LL * a * a % mod)
        if (n & 1) t = 1LL * t * a % mod;
    return t;
}

int main()
{
    int n;
    memset(ans, 0, sizeof(ans));
    scanf("%d", &n);
    sam.init();
    for (int i = 0; i < n; i++)
    {
        scanf("%s", buf);
        for (int j = 0; buf[j]; j++) sam.extend(buf[j] - 'a');
        sam.reset();
        s[i] = buf;
    }
    for (int i = 0; i < n; i++) scanf("%d", &val[i]);
    for (int i = 0; i < n; i++) sam.build(s[i], val[i], i);
    sam.build();
    for (int i = 1; i < maxn; i++) ans[i] = (ans[i - 1] + ans[i]) % mod;
    for (int i = 1; i < maxn; i++) ans[i] = (ans[i - 1] + ans[i]) % mod;
    p[0] = 1;
    for (int i = 1; i < maxn; i++) p[i] = 26LL * p[i - 1] % mod;
    for (int i = 2; i < maxn; i++) p[i] = (p[i - 1] + p[i]) % mod;
    for (int i = 1; i < maxn; i++) ans[i] = 1LL * ans[i] * Pow(p[i], mod - 2) % mod;
    int m;
    scanf("%d", &m);
    for (int i = 0, x; i < m; i++)
    {
        scanf("%d", &x);
        printf("%d\n", ans[x]);
    }
}