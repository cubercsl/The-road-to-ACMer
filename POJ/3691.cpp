// DNA repair, POJ3691

/*Sample Input
2
AAA
AAG
AAAG
2
A
TG
TGAATG
4
A
G
C
T
AGT
0
*/

#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
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

const int maxnode = 1005;
struct Trie
{
    int ch[maxnode][4], f[maxnode];
    bool val[maxnode]; //unsafe
    int sz;
    int newnode()
    {
        clr(ch[sz], -1);
        val[sz] = 0;
        return sz++;
    }
    void init() { sz = 0, newnode(); }

    inline int idx(char c)
    {
        switch (c)
        {
        case 'A': return 0;
        case 'G': return 1;
        case 'C': return 2;
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
            if (ch[u][c] == -1) ch[u][c] = newnode();
            u = ch[u][c];
        }
        val[u] = 1;
    }

    void build()
    {
        queue<int> q;
        f[0] = 0;
        int u = 0;
        for (int c = 0; c < 4; c++)
        {
            if (~ch[u][c])
                f[ch[u][c]] = 0, q.push(ch[u][c]);
            else
                ch[u][c] = 0;
        }
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            for (int c = 0; c < 4; c++)
            {
                if (~ch[u][c])
                {
                    f[ch[u][c]] = ch[f[u]][c];
                    if (val[f[ch[u][c]]]) val[ch[u][c]] = 1;
                    q.push(ch[u][c]);
                }
                else
                    ch[u][c] = ch[f[u]][c];
            }
        }
    }

    int dp[maxnode][maxnode];
    int solve(const char* s)
    {
        int n = strlen(s);
        clr(dp, 0x3f);
        dp[0][0] = 0;
        for (int i = 1; i <= n; i++)
            for (int u = 0; u < sz; u++)
                if (dp[i - 1][u] != INF)
                    for (int c = 0; c < 4; c++)
                        if (!val[ch[u][c]])
                            dp[i][ch[u][c]] = min(dp[i][ch[u][c]], dp[i - 1][u] + (idx(s[i - 1]) != c));
        /*
        for (int i = 0; i <= n; i++)
            for (int j = 0; j < sz; j++)
                printf("%d%c", dp[i][j] == INF ? -1 : dp[i][j], j != sz - 1 ? ' ' : '\n');
        for (int i = 0; i < sz; i++) printf("%3d: %d\n", i, val[i]);
        */
        int ret = INF;
        for (int i = 0; i < sz; i++)
            if (!val[i]) ret = min(ret, dp[n][i]);
        if (ret == INF) return -1;
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
    int n, kase = 0;
    char buf[maxnode];
    while (~scanf("%d", &n) && n)
    {
        ac.init();
        while (n--)
        {
            scanf("%s", buf);
            ac.insert(buf);
        }
        ac.build();
        scanf("%s", buf);
        printf("Case %d: %d\n", ++kase, ac.solve(buf));
    }
    return 0;
}
