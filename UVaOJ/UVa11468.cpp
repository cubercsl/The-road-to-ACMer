// Substring, UVa11468

/*Sample Input
2
1
a
2
a 0.5
b 0.5
2
2
ab
ab
2
a 0.2
b 0.8
2
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

const int maxn = 405;
struct Trie
{
    int ch[maxn][62], f[maxn];
    bool val[maxn];
    int sz, rt;
    int newnode()
    {
        clr(ch[sz], -1), val[sz] = 0;
        return sz++;
    }
    void init() { sz = 0, rt = newnode(); }
    inline int idx(char c)
    {
        if (isdigit(c))
            return c - '0';
        if (c >= 'a' && c <= 'z')
            return c - 'a' + 10;
        return c - 'A' + 36;
    };
    void insert(const char* s)
    {
        int u = 0, n = strlen(s);
        for (int i = 0; i < n; i++)
        {
            int c = idx(s[i]);
            if (ch[u][c] == -1) ch[u][c] = newnode();
            u = ch[u][c];
        }
        val[u] = 1;
    }
    void build()
    {
        queue<int> q;
        f[rt] = rt;
        for (int c = 0; c < 62; c++)
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
            for (int c = 0; c < 62; c++)
            {
                if (~ch[u][c])
                    f[ch[u][c]] = ch[f[u]][c], q.push(ch[u][c]);
                else
                    ch[u][c] = ch[f[u]][c];
            }
        }
    }
    double pro[62];
    double dp[maxn][105];
    bool vis[maxn][105];
    double dfs(int u, int L)
    {
        if (!L) return 1.0;
        if (vis[u][L]) return dp[u][L];
        vis[u][L] = 1;
        double& ret = dp[u][L];
        ret = 0.0;
        for (int c = 0; c < 63; c++)
            if (!val[ch[u][c]])
                ret += pro[c] * dfs(ch[u][c], L - 1);
        return ret;
    }
    double solve()
    {
        clr(pro, 0);
        int n;
        char buf[5];
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            scanf("%s", buf);
            scanf("%lf", &pro[idx(buf[0])]);
        }
        clr(dp, 0), clr(vis, 0);
        int L;
        scanf("%d", &L);
        return dfs(rt, L);
    }
};

Trie ac;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int T, kase = 0;
    char buf[25];
    scanf("%d", &T);
    while (T--)
    {
        ac.init();
        int k;
        scanf("%d", &k);
        while (k--)
        {
            scanf("%s", buf);
            ac.insert(buf);
        }
        ac.build();
        printf("Case #%d: %.6f\n", ++kase, ac.solve());
    }
    return 0;
}
