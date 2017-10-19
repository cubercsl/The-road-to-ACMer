// Wireless Password, HDU2825

/*Sample Input
10 2 2
hello
world
4 1 1
icpc
10 0 0
0 0 0
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
const int mod = 20090717;
const double eps = 1e-6;

const int maxn = 255;
struct Trie
{
    int ch[maxn][26], f[maxn], val[maxn];
    int sz, rt;
    int newnode()
    {
        clr(ch[sz], -1), val[sz] = 0;
        return sz++;
    }
    void init() { sz = 0, rt = newnode(); }
    inline int idx(char c) { return c - 'a'; };
    void insert(const char* s, const int id)
    {
        int u = 0, n = strlen(s);
        for (int i = 0; i < n; i++)
        {
            int c = idx(s[i]);
            if (ch[u][c] == -1) ch[u][c] = newnode();
            u = ch[u][c];
        }
        val[u] |= (1 << id);
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
    int dp[30][maxn][1 << 10];
    int solve(int n, int m, int kk)
    {
        clr(dp, 0);
        dp[0][0][0] = 1;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < sz; j++)
                for (int k = 0; k < (1 << m); k++)
                    if (dp[i][j][k])
                        for (int c = 0; c < 26; c++)
                        {
                            int jj = ch[j][c];
                            (dp[i + 1][jj][k | val[jj]] += dp[i][j][k]) %= mod;
                        }
        /*puts("debug:");
        for (int i = 0; i < n; i++)
            for (int j = 0; j < sz; j++)
                for (int k = 0; k < (1 << m); k++)
                    printf("dp[%4d][%4d][%4d] = %d\n", i, j, k, dp[i][j][k]);
        puts("-----");*/
        int ans = 0;
        for (int i = 0; i < (1 << m); i++)
            if (__builtin_popcount(i) >= kk)
                for (int j = 0; j < sz; j++)
                    (ans += dp[n][j][i]) %= mod;
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
    int n, m, k;
    char buf[30];
    while (~scanf("%d%d%d", &n, &m, &k) && n + m + k)
    {
        ac.init();
        for (int i = 0; i < m; i++)
        {
            scanf("%s", buf);
            ac.insert(buf, i);
        }
        ac.build();
        printf("%d\n", ac.solve(n, m, k));
    }
    return 0;
}
