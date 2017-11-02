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

int dp[12][1 << 10];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    int T, buf, kase = 0;
    scanf("%d", &T);
    while (T--)
    {
        int n, m;
        VI pro[10], exp[10], tmp;
        ll P[10], E[10];
        clr(P, 0), clr(E, 0);
        scanf("%d%d", &n, &m);

        for (int i = 0; i < n; i++)
        {
            int c;
            scanf("%d", &c);
            for (int j = 0; j < c; j++)
            {
                scanf("%d", &buf);
                pro[i].pb(buf);
                tmp.pb(buf);
            }
        }
        for (int i = 0; i < m; i++)
        {
            int d;
            scanf("%d", &d);
            for (int j = 0; j < d; j++)
            {
                scanf("%d", &buf);
                exp[i].pb(buf);
                tmp.pb(buf);
            }
        }

        sort(tmp.begin(), tmp.end());
        tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
        for (int i = 0; i < n; i++)
            for (auto& t : pro[i])
            {
                t = lower_bound(tmp.begin(), tmp.end(), t) - tmp.begin();
                P[i] |= (1LL << t);
            }
        for (int i = 0; i < m; i++)
            for (auto& t : exp[i])
            {
                t = lower_bound(tmp.begin(), tmp.end(), t) - tmp.begin();
                E[i] |= (1LL << t);
            }

        clr(dp, 0);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < (1 << m); j++)
            {
                dp[i & 1 ^ 1][j] = dp[i & 1][j];
                for (int k = 0; k < j; k++)
                    if ((k & j) == k)
                    {
                        // printf("dp[%d][%d] = %d\n", i + 1, j, dp[i + 1][j]);
                        ll have = 0;
                        for (int ii = 0; ii < m; ii++)
                            if (((j - k) & (1 << ii)))
                                have |= E[ii];
                        // printf("have = %lld\n", have);
                        if ((P[i] & have) == P[i])
                            dp[i & 1 ^ 1][j] = max(dp[i & 1 & 1][j], dp[i & 1][k] + 1);
                    }
            }
        printf("Case #%d: %d\n", ++kase, dp[n & 1][(1 << m) - 1]);
    }
    return 0;
}
