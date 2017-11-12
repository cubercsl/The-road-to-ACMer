// Resource Archiver, HDU3247

/*Sample Input
2 2
1110
0111
101
1001
0 0
*/

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

const int maxn = 5e5 + 5;
struct Trie
{
    int ch[maxn][2];
    int val[maxn], f[maxn];
    int sz, rt;
    inline int newnode()
    {
        clr(ch[sz], -1), val[sz] = 0;
        return sz++;
    }
    inline int idx(char c) { return c - '0'; }
    void init() { sz = 0, rt = newnode(); }
    void insert(const char* s, const int& id)
    {
        int n = strlen(s), u = rt;
        for (int i = 0; i < n; i++)
        {
            int c = idx(s[i]);
            if (ch[u][c] == -1) ch[u][c] = newnode();
            u = ch[u][c];
        }
        val[u] |= id;
    }
    void build()
    {
        queue<int> q;
        f[rt] = rt;
        for (int c = 0; c < 2; c++)
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
            for (int c = 0; c < 2; c++)
            {
                if (~ch[u][c])
                    f[ch[u][c]] = ch[f[u]][c], q.push(ch[u][c]);
                else
                    ch[u][c] = ch[f[u]][c];
            }
        }
    }
    vector<int> w;
    int G[1 << 10][1 << 10];
    int vis[maxn];
    void bfs(int s)
    {
        queue<int> q;
        clr(vis, -1);
        vis[w[s]] = 0;
        q.push(w[s]);
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            for (int c = 0; c < 2; c++)
            {
                int v = ch[u][c];
                if (~vis[v] || val[v] == -1) continue;
                vis[v] = vis[u] + 1;
                q.push(v);
            }
        }
        for (int i = 0; i < w.size(); i++) G[s][i] = vis[w[i]];
    }
    int dp[1 << 10][1 << 10];
    int solve(int n)
    {
        w.clear();
        clr(G, 0x3f);
        clr(dp, 0x3f);
        for (int i = 0; i < sz; i++)
            if (i == 0 || val[i] > 0) w.pb(i);
        for (int i = 0; i < w.size(); i++) bfs(i);
        dp[0][0] = 0;
        for (int i = 0; i < (1 << n); i++)
            for (int j = 0; j < w.size(); j++)
                if (dp[i][j] != INF)
                    for (int k = 0; k < w.size(); k++)
                        if (~G[j][k])
                            dp[i | val[w[k]]][k] = min(dp[i | val[w[k]]][k], dp[i][j] + G[j][k]);
        int ans = INF;
        for (int i = 0; i < w.size(); i++)
            ans = min(ans, dp[(1 << n) - 1][i]);
        return ans;
    }
};

Trie ac;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n, m;
    char buf[1005];
    while (~scanf("%d%d", &n, &m) && n + m)
    {
        ac.init();
        for (int i = 0; i < n; i++)
        {
            scanf("%s", buf);
            ac.insert(buf, 1 << i);
        }
        for (int i = 0; i < m; i++)
        {
            scanf("%s", buf);
            ac.insert(buf, -1);
        }
        ac.build();
        printf("%d\n", ac.solve(n));
    }
    return 0;
}
