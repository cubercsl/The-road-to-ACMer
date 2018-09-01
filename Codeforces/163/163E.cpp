#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1 << 20;
struct Trie
{
    int ch[N][26], f[N], val[N], pos[N], vis[N];
    int sz, rt;
    int newnode()
    {
        memset(ch[sz], -1, sizeof(ch[sz]));
        val[sz] = 0;
        return sz++;
    }
    void init() { sz = 0, rt = newnode(); }
    inline int idx(const char& c) { return c - 'a'; }
    void insert(const char* s, int id)
    {
        int u = rt;
        for (int i = 0; s[i]; i++)
        {
            int c = idx(s[i]);
            if (!~ch[u][c]) ch[u][c] = newnode();
            u = ch[u][c];
        }
        val[u]++, pos[id] = u;
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
            val[u] += val[f[u]];
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
    }
    void dfs(int u)
    {
        in[u] = ++dfn;
        for (auto& v : G[u]) dfs(v);
        out[u] = dfn;
    }
    void modify(int id, int d)
    {
        if (vis[id] && d > 0 || !vis[id] && d < 0) return;
        vis[id] ^= 1;
        int u = pos[id];
        update(in[u], d);
        update(out[u] + 1, -d);
    }

    int bit[N];
    void update(int x, int v)
    {
        for (; x < N; x += x & -x) bit[x] += v;
    }
    int query(int x)
    {
        int t = 0;
        for (; x; x -= x & -x) t += bit[x];
        return t;
    }
    int solve(const char* s)
    {
        int u = rt, ans = 0;
        for (int i = 0; s[i]; i++)
        {
            int c = idx(s[i]);
            u = ch[u][c];
            ans += query(in[u]);
        }
        return ans;
    }

} ac;

char s[N];
int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    ac.init();
    for (int i = 1; i <= k; i++)
    {
        scanf("%s", s);
        ac.insert(s, i);
    }
    ac.build();
    for (int i = 1; i <= k; i++) ac.modify(i, 1);
    for (int i = 0; i < n; i++)
    {
        static char op;
        static int x;
        while (op = getchar(),( op != '+' && op != '-' && op != '?'))
            ;
        if (op == '+') scanf("%d", &x), ac.modify(x, 1);
        if (op == '-') scanf("%d", &x), ac.modify(x, -1);
        if (op == '?')
        {
            scanf("%s", s);
            printf("%d\n", ac.solve(s));
        }
    }
    return 0;
}