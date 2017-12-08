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

const int maxn = 3e5 + 5;
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
    void insert(const string& s, const int& id)
    {
        int u = 0, n = s.length();
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

    int dp[1 << 3][maxn];
    void debug()
    {
        for (int i = 0; i < (1 << 3); i++)
            for (int j = 0; j < sz; j++)
                printf("dp[%d][%d] = %d\n", i, j, dp[i][j]);
    }
    int solve()
    {
        clr(dp, -1);
        dp[0][0] = 0;
        queue<PII> q;
        q.push(mp(0, 0));
        while (!q.empty())
        {
            PII tmp = q.front();
            q.pop();
            int u = tmp.Y, st = tmp.X;
            for (int c = 0; c < 26; c++)
            {
                int nxt = ch[u][c];
                int nst = (st | val[nxt]);
                if (~dp[nst][nxt]) continue;
                dp[nst][nxt] = dp[st][u] + 1;
                if (nst == (1 << 3) - 1) return dp[nst][nxt];
                q.push(mp(nst, nxt));
            }
        }
        return -1;
    }
};

Trie ac;
string s[3];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    while (cin >> s[0] >> s[1] >> s[2])
    {
        ac.init();
        for (int i = 0; i < 3; i++) ac.insert(s[i], i);
        ac.build();
        printf("%d\n", ac.solve());
    }
    return 0;
}
