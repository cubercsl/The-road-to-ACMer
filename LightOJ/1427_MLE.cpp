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

const int maxn = 1e6 + 5;
struct SAM
{
    int len[maxn << 1], link[maxn << 1], ch[maxn << 1][26];
    int dp[maxn << 1];
    int sz, rt, last;
    int newnode(int x = 0, int cnt = 1)
    {
        dp[sz] = cnt;
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
                int nq = newnode(len[p] + 1, 0);
                memcpy(ch[nq], ch[q], sizeof(ch[q]));
                link[nq] = link[q], link[q] = link[np] = nq;
                for (; ~p && ch[p][c] == q; p = link[p]) ch[p][c] = nq;
            }
        }
        last = np;
    }

    int topsam[maxn << 1];
    int topcnt[maxn];
    void build(int n)
    {
        clr(topcnt, 0);
        for (int i = 0; i < sz; i++) topcnt[len[i]]++;
        for (int i = 0; i < n; i++) topcnt[i + 1] += topcnt[i];
        for (int i = 0; i < sz; i++) topsam[--topcnt[len[i]]] = i;
        for (int i = sz - 1; ~i; i--)
        {
            int u = topsam[i];
            if (~link[u]) dp[link[u]] += dp[u];
        }
    }
    int find(const char* s)
    {
        int u = rt;
        for (int i = 0; s[i]; i++)
        {
            int c = s[i] - 'a';
            if (ch[u][c] == -1) return 0;
            u = ch[u][c];
        }
        return dp[u];
    }
} sam;

char s[maxn];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int T, kase = 0;
    scanf("%d", &T);
    while (T--)
    {
        sam.init();
        int n, m = 0;
        scanf("%d", &n);
        scanf("%s", s);
        for (int i = 0; s[i]; i++, m++) sam.extend(s[i] - 'a');
        sam.build(m);
        printf("Case %d:\n", ++kase);
        while (n--)
        {
            scanf("%s", s);
            printf("%d\n", sam.find(s));
        }
    }
    return 0;
}
