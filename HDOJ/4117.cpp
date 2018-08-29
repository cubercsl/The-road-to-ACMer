#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1 << 18;
struct Trie
{
    int ch[N][26], f[N];
    int sz, rt;
    int newnode()
    {
        memset(ch[sz], -1, sizeof(ch[sz]));
        val[sz] = 0;
        return sz++;
    }
    void init() { sz = 0, rt = newnode(); }
    inline int idx(const char& c) { return c - 'a'; }
    void insert(const char* s)
    {
        int u = rt;
        for (int i = 0; s[i]; i++)
        {
            int c = idx(s[i]);
            if (!~ch[u][c]) ch[u][c] = newnode();
            u = ch[u][c];
        }
    }
    vector<int> G[N];
    int in[N], out[N], dfn;
    void build()
    {
        queue<int> q;
        f[rt] = rt;
        for (int c = 0; c < 26; c++)
        {
            if (~ch[rt][c])
                f[ch[rt][c]] = rt, q.push(ch[rt][c]);
            else
                ch[rt][c] = rt;
        }
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            for (int c = 0; c < 26; c++)
            {
                if (~ch[u][c])
                    f[ch[u][c]] = ch[f[u]][c], q.push(ch[u][c]);
                else
                    ch[u][c] = ch[f[u]][c];
            }
        }
        for (int i = 1; i < sz; i++) G[f[i]].push_back(i);
        dfn = 0;
        dfs(rt);
        for (int i = 0; i < sz; i++) G[i].clear();
    }
    void dfs(int u)
    {
        in[u] = ++dfn;
        for (auto& v : G[u]) dfs(v);
        out[u] = dfn;
    }
#define lson o << 1
#define rson o << 1 | 1
#define Lson l, m, o << 1
#define Rson m + 1, r, o << 1 | 1
    int val[N << 2], setv[N << 2];
    inline void pushup(int o) { val[o] = max(val[lson], val[rson]); }
    inline void pushdown(int o)
    {
        if (!setv[o]) return;
        setv[lson] = max(setv[lson], setv[o]);
        setv[rson] = max(setv[rson], setv[o]);
        val[lson] = max(val[lson], setv[o]);
        val[rson] = max(val[rson], setv[o]);
        setv[o] = 0;
    }
    void build(int l, int r, int o)
    {
        setv[o] = 0;
        if (l == r)
        {
            val[o] = 0;
            return;
        }
        const int m = l + r >> 1;
        build(Lson), build(Rson);
        pushup(o);
    }
    void update(int L, int R, int v, int l, int r, int o)
    {
        if (L <= l && r <= R)
        {
            val[o] = max(val[o], v);
            setv[o] = max(setv[o], v);
            return;
        }
        pushdown(o);
        const int m = l + r >> 1;
        if (L <= m) update(L, R, v, Lson);
        if (m < R) update(L, R, v, Rson);
        pushup(o);
    }
    int query(int p, int l, int r, int o)
    {
        if (l == r) return val[o];
        pushdown(o);
        const int m = l + r >> 1;
        if (p <= m) return query(p, Lson);
        return query(p, Rson);
    }
    int solve(const vector<pair<string, int>>& v)
    {
        build(1, sz, 1);
        int ans = 0;
        for (auto& it : v)
        {
            const string& s = it.first;
            const int& w = it.second;
            int tmp = 0, u = rt;
            for (auto& t : s)
            {
                int c = idx(t);
                u = ch[u][c];
                tmp = max(tmp, query(in[u], 1, sz, 1));
            }
            tmp += w;
            ans = max(ans, tmp);
            update(in[u], out[u], tmp, 1, sz, 1);
        }
        return ans;
    }

} ac;

char buf[N];

int main()
{
    int T, kase = 0;
    scanf("%d", &T);
    while (T--)
    {
        int n;
        scanf("%d", &n);
        vector<pair<string, int>> v;
        ac.init();
        for (int i = 0, w; i < n; i++)
        {
            scanf("%s%d", buf, &w);
            v.emplace_back(buf, w);
            ac.insert(buf);
        }
        ac.build();
        int ans = ac.solve(v);
        printf("Case #%d: %d\n", ++kase, ans);
    }
}