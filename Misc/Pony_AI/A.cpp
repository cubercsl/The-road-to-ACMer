#include <bits/stdc++.h>
using namespace std;

const int maxn = 1 << 17;
struct SAM
{
    int len[maxn << 1], link[maxn << 1], ch[maxn << 1][26];
    int sz, rt, last;
    int newnode(int x = 0)
    {
        len[sz] = x;
        link[sz] = -1;
        memset(ch[sz], -1, sizeof(ch[sz]));
        return sz++;
    }
    void init()
    {
        sz = last = 0, rt = newnode();
        memset(dp, -1, sizeof(dp));
    }
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
    int dp[maxn << 1];
    int find(const char* s)
    {
        int u = rt;
        for (int i = 0; s[i]; i++) u = ch[u][s[i] - 'a'];
        return dfs(u);
    }
    int dfs(int u)
    {
        if (~dp[u]) return dp[u];
        bool vis[30];
        memset(vis, 0, sizeof(vis));
        for (int i = 0; i < 26; i++)
            if (~ch[u][i])
                vis[dfs(ch[u][i])] = true;
        for (int i = 0;; i++)
            if (!vis[i]) return dp[u] = i;
    }
} sam;

char s[maxn], t[maxn];

int main()
{
    while (~scanf("%s", t))
    {
        sam.init();
        for (int i = 0; t[i]; i++) sam.extend(t[i] - 'a');
        int n;
        scanf("%d", &n);
        int sum = 0;
        while (n--)
        {
            scanf("%s", s);
            sum ^= sam.find(s);
        }
        puts(sum ? "Alice" : "Bob");
    }
}
