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
const int mod = 2012;
const double eps = 1e-6;

const int maxn = 100005;
struct SAM
{
    int len[maxn << 1], link[maxn << 1], ch[maxn << 1][12];
    int sz, rt, last;
    int newnode(int x = 0)
    {
        len[sz] = x;
        link[sz] = -1;
        clr(ch[sz], -1);
        return sz++;
    }
    void init() { sz = last = 0, rt = newnode(); }
    void extend(int c)
    {
        int np = newnode(len[last] + 1);
        int p;
        for (p = last; ~p && ch[p][c] == -1; p = link[p]) ch[p][c] = np;
        if (p == -1)
            link[np] = rt;
        else
        {
            int q = ch[p][c];
            if (len[p] + 1 == len[q])
                link[np] = q;
            else
            {
                int nq = newnode(len[p] + 1);
                memcpy(ch[nq], ch[q], sizeof(ch[q]));
                link[nq] = link[q], link[q] = link[np] = nq;
                for (; ~p && ch[p][c] == q; p = link[p]) ch[p][c] = nq;
            }
        }
        last = np;
    }
    int topcnt[maxn];
    int topsam[maxn << 1];
    int dp[maxn << 1], sum[maxn << 1];
    int solve()
    {
        int ret = 0;
        clr(topcnt, 0);
        clr(dp, 0);
        clr(sum, 0);
        for (int i = 0; i < sz; i++) topcnt[len[i]]++;
        for (int i = 0; i < maxn - 1; i++) topcnt[i + 1] += topcnt[i];
        for (int i = 0; i < sz; i++) topsam[--topcnt[len[i]]] = i;
        dp[rt] = 1;
        for (int i = 0; i < sz; i++)
        {
            int u = topsam[i];
            for (int c = 0; c < 10; c++)
            {
                if (u == 0 && c == 0) continue;
                if (~ch[u][c])
                {
                    int v = ch[u][c];
                    (dp[v] += dp[u]) %= mod;
                    (sum[v] += sum[u] * 10 + dp[u] * c) %= mod;
                }
            }
            (ret += sum[u]) %= mod;
        }
        return ret;
    }
};

SAM sam;
char buf[maxn];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n;
    while (~scanf("%d", &n))
    {
        sam.init();
        while (n--)
        {
            scanf("%s", buf);
            int m = strlen(buf);
            sam.last = 0;
            for (int i = 0; i < m; i++) sam.extend(buf[i] - '0');
        }
        printf("%d\n", sam.solve());
    }
    return 0;
}
