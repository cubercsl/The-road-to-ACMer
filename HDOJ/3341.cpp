// Lost's revenge, HDU3341

/*Sample Input
3
AC
CG
GT
CGAT
1
AA
AAA
0
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

const int maxn = 505;
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
        val[u]++;
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
            val[u] += val[f[u]];
            for (int c = 0; c < 4; c++)
            {
                if (~ch[u][c])
                    f[ch[u][c]] = ch[f[u]][c], q.push(ch[u][c]);
                else
                    ch[u][c] = ch[f[u]][c];
            }
        }
    }
    int cnt[4];
    int dp[maxn][15000];
    int hash[42][42][42][42];
    int solve(const char* s)
    {
        clr(cnt, 0);
        clr(dp, -1);
        int len = strlen(s);
        for (int i = 0; i < len; i++)
            cnt[idx(s[i])]++;
        int tot = 0;
        for (int a = 0; a <= cnt[0]; a++)
            for (int c = 0; c <= cnt[1]; c++)
                for (int g = 0; g <= cnt[2]; g++)
                    for (int t = 0; t <= cnt[3]; t++)
                        hash[a][c][g][t] = tot++;
        int ans = 0;
        dp[0][0] = 0;
        for (int a = 0; a <= cnt[0]; a++)
            for (int c = 0; c <= cnt[1]; c++)
                for (int g = 0; g <= cnt[2]; g++)
                    for (int t = 0; t <= cnt[3]; t++)
                        if (a + c + g + t)
                        {
                            int h1 = hash[a][c][g][t];
                            for (int i = 0; i < sz; i++)
                                for (int j = 0; j < 4; j++)
                                {
                                    int h2;
                                    if (j == 0 && a >= 1)
                                        h2 = hash[a - 1][c][g][t];
                                    else if (j == 1 && c >= 1)
                                        h2 = hash[a][c - 1][g][t];
                                    else if (j == 2 && g >= 1)
                                        h2 = hash[a][c][g - 1][t];
                                    else if (j == 3 && t >= 1)
                                        h2 = hash[a][c][g][t - 1];
                                    else
                                        continue;
                                    if (~dp[i][h2])
                                    {
                                        dp[ch[i][j]][h1] = max(dp[ch[i][j]][h1], dp[i][h2] + val[ch[i][j]]);
                                        ans = max(dp[ch[i][j]][h1], ans);
                                    }
                                }
                        }
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
    char buf[45];
    int n;
    int kase = 0;
    while (~scanf("%d", &n) && n)
    {
        ac.init();
        for (int i = 0; i < n; i++)
        {
            scanf("%s", buf);
            ac.insert(buf);
        }
        scanf("%s", buf);
        ac.build();
        int ans = ac.solve(buf);
        printf("Case %d: %d\n", ++kase, ans);
    }
    return 0;
}
