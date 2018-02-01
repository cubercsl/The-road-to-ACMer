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
const int mod = 1e9 + 9;
const double eps = 1e-6;

const int maxn = 105;
struct Trie
{
    int ch[maxn][4], f[maxn], val[maxn];
    int sz, rt;
    int newnode()
    {
        clr(ch[sz], -1), val[sz] = 0;
        return sz++;
    }
    void init() { sz = 0, rt = newnode(); }
    inline int idx(char c)
    {
        switch (c)
        {
        case 'A': return 0;
        case 'C': return 1;
        case 'G': return 2;
        case 'T': return 3;
        }
        return -1;
    }
    void insert(const char* s)
    {
        int u = 0, n = strlen(s);
        for (int i = 0; i < n; i++)
        {
            int c = idx(s[i]);
            assert(~c);
            if (ch[u][c] == -1) ch[u][c] = newnode();
            u = ch[u][c];
        }
        val[u] = n;
    }
    void build()
    {
        queue<int> q;
        f[rt] = rt;
        for (int c = 0; c < 4; c++)
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
            val[u] = max(val[u], val[f[u]]);
            for (int c = 0; c < 4; c++)
            {
                if (~ch[u][c])
                    f[ch[u][c]] = ch[f[u]][c], q.push(ch[u][c]);
                else
                    ch[u][c] = ch[f[u]][c];
            }
        }
    }
    ll dp[1005][maxn][15];
    ll solve(int n, int m)
    {
        clr(dp, 0);
        dp[0][0][0] = 1;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < sz; j++)
                for (int k = 0; k <= 10; k++)
                    for (int c = 0; c < 4; c++)
                    {
                        int t = ch[j][c];
                        if (val[t] > k)
                            (dp[i + 1][t][0] += dp[i][j][k]) %= mod;
                        else
                            (dp[i + 1][t][k + 1] += dp[i][j][k]) %= mod;
                    }
        ll ret = 0;
        for (int i = 0; i < sz; i++) (ret += dp[n][i][0]) %= mod;
        return ret;
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
    char buf[12];
    while (~scanf("%d%d", &n, &m))
    {
        ac.init();
        for (int i = 0; i < m; i++)
        {
            scanf("%s", buf);
            ac.insert(buf);
        }
        ac.build();
        printf("%lld\n", ac.solve(n, m));
    }
    return 0;
}
