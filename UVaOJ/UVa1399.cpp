// Puzzle, UVa1399

/*Sample Input
3
24
AAA
AB
BA
BB
24
AAA
BBB
ABAB
BBAA
37
AA
ABA
BAC
BB
BC
CA
CC
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

const int maxn = 1 << 16;
struct Trie
{
    int ch[maxn][26];
    int f[maxn];
    bool val[maxn];
    int sz, rt;
    int newnode()
    {
        clr(ch[sz], -1), val[sz] = 0;
        return sz++;
    }
    void init() { sz = 0, rt = newnode(); }
    inline int idx(char c) { return c - 'A'; };

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
                {
                    f[ch[u][c]] = ch[f[u]][c];
                    val[ch[u][c]] |= val[f[ch[u][c]]];
                    q.push(ch[u][c]);
                }
                else
                    ch[u][c] = ch[f[u]][c];
            }
        }
    }
};
bool vis[maxn];
int dp[maxn], pre[maxn];
Trie ac;

int dfs(int u, int n)
{
    if (vis[u]) return -1;
    if (~dp[u]) return dp[u];
    vis[u] = 1;
    int& ret = dp[u];
    ret = 0;
    for (int i = n - 1; ~i; i--)
    {
        int v = ac.ch[u][i];
        if (!ac.val[v])
        {
            int tmp = dfs(v, n);
            if (tmp == -1) return -1;
            if (tmp + 1 > ret) ret = tmp + 1, pre[u] = i;
        }
    }
    vis[u] = 0;
    return ret;
}

void print(int u)
{
    while (~pre[u])
    {
        printf("%c", 'A' + pre[u]);
        u = ac.ch[u][pre[u]];
    }
    puts("");
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
freopen("1.out", "w", stdout);
#endif
    int T;
    char buf[55];
    scanf("%d", &T);
    while (T--)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        ac.init();
        while (m--)
        {
            scanf("%s", buf);
            ac.insert(buf);
        }
        ac.build();
        clr(vis, 0);
        clr(dp, -1);
        clr(pre, -1);
        if (~dfs(0, n) && dp[0])
            print(0);
        else
            puts("No");
    }
    return 0;
}
