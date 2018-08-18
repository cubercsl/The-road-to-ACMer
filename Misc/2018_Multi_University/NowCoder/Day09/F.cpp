#include <bits/stdc++.h>
using namespace std;

const int maxn = 1 << 17;
struct Trie
{
    int ch[maxn][26], f[maxn], val[maxn];
    int sz, rt;
    int newnode()
    {
        memset(ch[sz], -1, sizeof(ch[sz])), val[sz] = 0;
        return sz++;
    }
    void init() { sz = 0, rt = newnode(); }
    inline int idx(char c) { return c - 'a'; };
    void insert(const char* s, int id)
    {
        int u = 0, n = strlen(s);
        for (int i = 0; i < n; i++)
        {
            int c = idx(s[i]);
            if (ch[u][c] == -1) ch[u][c] = newnode();
            u = ch[u][c];
        }
        val[u] |= 1 << id;
    }
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
            val[u] |= val[f[u]];
            for (int c = 0; c < 26; c++)
            {
                if (~ch[u][c])
                    f[ch[u][c]] = ch[f[u]][c], q.push(ch[u][c]);
                else
                    ch[u][c] = ch[f[u]][c];
            }
        }
    }
    int d[maxn];
    vector<int> G[maxn];

    void solve(const char* op)
    {
        for (int u = 0; u < sz; u++)
            for (int c = 0; c < 26; c++)
                if (~ch[u][c])
                    G[ch[u][c]].push_back(u);
        memset(d, -1, sizeof(d));
        queue<int> q;
        for (int i = 0; i < sz; i++)
            if (val[i]) q.push(i), d[i] = 0;
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            for (auto& v : G[u])
            {
                if (~d[v]) continue;
                d[v] = d[u] + 1;
                q.push(v);
            }
        }
        stack<int> s;
        int u = rt;
        s.push(u);
        printf("%d\n", d[u]);
        for (int i = 0; op[i]; i++)
        {
            if (op[i] == '-')
            {
                s.pop();
                if (!s.empty())
                    u = s.top();
                else
                    s.push(0);
                printf("%d\n", d[u]);
            }
            else
            {
                u = ch[u][op[i] - 'a'];
                s.push(u);
                printf("%d\n", d[u]);
            }
        }
    }
} ac;

char s[maxn];

int main()
{
    int n;
    scanf("%d", &n);
    ac.init();
    for (int i = 0; i < n; i++)
    {
        scanf("%s", s);
        ac.insert(s, i);
    }
    ac.build();
    scanf("%s", s);
    ac.solve(s);
}