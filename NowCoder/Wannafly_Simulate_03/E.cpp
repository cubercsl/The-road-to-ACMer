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

const int maxn = 1 << 17;
vector<int> G[maxn];
int a[maxn], b[maxn];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n, k;
    while (~scanf("%d%d", &n, &k))
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d", a + i);
            b[i] = a[i];
        }
        sort(b, b + n);
        int tot = unique(b, b + n) - b;
        for (int i = 0; i < n; i++)
        {
            a[i] = lower_bound(b, b + tot, a[i]) - b;
            G[a[i]].pb(i);
        }
        int ans = 0;
        for (int i = 0; i < tot; i++)
        {
            deque<int> q;
            int now = k;
            int r = 0;
            while (r < G[i].size())
            {
                int& v = G[i][r];
                if (q.empty())
                {
                    q.push_back(v);
                    r++;
                }
                else
                {
                    int t = v - q.back() - 1;
                    if (t <= now)
                    {
                        now -= t;
                        q.push_back(v);
                        r++;
                    }
                    else
                    {
                        t = q.front();
                        q.pop_front();
                        if (!q.empty()) t = q.front() - t - 1, now += t;
                    }
                }
                if (!q.empty())
                    ans = max(ans, q.back() - q.front() + 1 - (k - now));
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
