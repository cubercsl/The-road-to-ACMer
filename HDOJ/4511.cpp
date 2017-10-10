// 小明系列故事——女友的考验, HDU4511

/*Sample Input
3 1
1 1
2 1
3 1
2
1 2

2 1
0 0
1 1
2
1 2

5 3
0 0
5 3
1 2
1 22
5 21
3
1 2 3
2
4 5
2
1 5

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

typedef pair<double, double> Point;
const int maxn = 505;
struct Trie
{
    int ch[maxn][55], f[maxn];
    bool val[maxn];
    int sz, rt;
    int newnode()
    {
        clr(ch[sz], -1), val[sz] = 0;
        return sz++;
    }
    void init() { sz = 0, rt = newnode(); }
    void insert(const int* s, int n)
    {
        int u = 0;
        for (int i = 0; i < n; i++)
        {
            int c = s[i];
            if (ch[u][c] == -1) ch[u][c] = newnode();
            u = ch[u][c];
        }
        val[u] = 1;
    }
    void build(int n)
    {
        queue<int> q;
        f[rt] = rt;
        for (int c = 0; c < n; c++)
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
            for (int c = 0; c < n; c++)
            {
                if (~ch[u][c])
                    f[ch[u][c]] = ch[f[u]][c], q.push(ch[u][c]);
                else
                    ch[u][c] = ch[f[u]][c];
            }
        }
    }
    inline double dist(Point a, Point b)
    {
        double dx = a.X - b.X, dy = a.Y - b.Y;
        return sqrt(dx * dx + dy * dy);
    }
    Point P[55];
    double dp[55][maxn];
    void input(int n)
    {
        for (int i = 0; i < n; i++) scanf("%lf%lf", &P[i].X, &P[i].Y);
    }
    double solve(int n)
    {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < sz; j++)
                dp[i][j] = 1e20;
        dp[0][ch[rt][0]] = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < sz; j++)
                if (dp[i][j] < INF)
                    for (int k = i + 1; k < n; k++)
                        if (!val[ch[j][k]])
                            dp[k][ch[j][k]] = min(dp[k][ch[j][k]], dp[i][j] + dist(P[i], P[k]));
        double ans = 1e20;
        for (int i = 0; i < sz; i++) ans = min(ans, dp[n - 1][i]);
        if (ans < 1e20) return ans;
        return -1;
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
    int buf[10];
    while (~scanf("%d%d", &n, &m) && n + m)
    {
        ac.init();
        ac.input(n);
        while (m--)
        {
            int k, tmp;
            scanf("%d", &k);
            for (int i = 0; i < k; i++)
            {
                scanf("%d", &tmp);
                buf[i] = tmp - 1;
            }
            ac.insert(buf, k);
        }
        ac.build(n);
        double ans = ac.solve(n);
        if (ans < 0)
            puts("Can not be reached!");
        else
            printf("%.2f\n", ans);
    }
    return 0;
}
