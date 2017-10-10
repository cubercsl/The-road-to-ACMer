// Ring, HDU2296

/*Sample Input
2
7 2
love
ever
5 5
5 1
ab
5
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

const int maxn = 2005;
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
    void insert(const string& s, int v)
    {
        int u = 0, n = s.length();
        for (int i = 0; i < n; i++)
        {
            int c = idx(s[i]);
            if (ch[u][c] == -1) ch[u][c] = newnode();
            u = ch[u][c];
        }
        val[u] = v;
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
            val[u] += val[f[u]];
            for (int c = 0; c < 26; c++)
            {
                if (~ch[u][c])
                {
                    f[ch[u][c]] = ch[f[u]][c];
                    q.push(ch[u][c]);
                }
                else
                    ch[u][c] = ch[f[u]][c];
            }
        }
    }

    int dp[55][maxn];
    string path[55][maxn];
    string solve(int n)
    {
        clr(dp, -1);
        for (int i = 0; i <= n; i++)
            for (int j = 0; j < sz; j++)
                path[i][j].clear();
        dp[0][0] = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < sz; j++)
                if (~dp[i][j])
                    for (int k = 0; k < 26; k++)
                    {
                        int u = ch[j][k];
                        char c = 'a' + k;
                        if (dp[i][j] + val[u] > dp[i + 1][u])
                        {
                            dp[i + 1][u] = dp[i][j] + val[u];
                            path[i + 1][u] = path[i][j] + c;
                        }
                        else if (dp[i][j] + val[u] == dp[i + 1][u])
                        {
                            dp[i + 1][u] = dp[i][j] + val[u];
                            path[i + 1][u] = min(path[i + 1][u], path[i][j] + c);
                        }
                    }
        /*for (int i = 0; i <= n; i++)
            for (int j = 0; j < sz; j++)
                printf("%3d%c", dp[i][j], j != sz - 1 ? ' ' : '\n');*/
        int ans = 0, len;
        for (int i = 0; i <= n; i++)
            for (int j = 0; j < sz; j++)
                if (ans < dp[i][j]) ans = dp[i][j], len = i;
        string ret;
        if (ans == 0) return ret;
        for (int j = 0; j < sz; j++)
            if (dp[len][j] == ans && (ret > path[len][j] || ret == ""))
                ret = path[len][j];
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
    int T, n, m, val;
    string s[105];
    cin >> T;
    while (T--)
    {
        scanf("%d%d", &n, &m);
        for (int i = 0; i < m; i++)
            cin >> s[i];
        ac.init();
        for (int i = 0; i < m; i++)
        {
            cin >> val;
            ac.insert(s[i], val);
        }
        ac.build();
        cout << ac.solve(n) << endl;
    }
    return 0;
}
