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
ll w[maxn], d[maxn];
ll a[maxn], b[maxn];
typedef pair<ll, ll> Pll;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    int T, kase = 0;
    scanf("%d", &T);
    while (T--)
    {
        int l, m, n;
        scanf("%d%d%d", &l, &n, &m);
        for (int i = 0; i < n; i++)
            scanf("%lld", w + i);
        for (int i = 0; i < m; i++)
            scanf("%lld", d + i);
        priority_queue<Pll, vector<Pll>, greater<Pll> > q;
        for (int i = 0; i < n; i++)
            q.push(mp(w[i], w[i]));
        for (int i = 0; i < l; i++)
        {
            Pll tmp = q.top();
            q.pop();
            a[i] = tmp.X;
            q.push(mp(tmp.X + tmp.Y, tmp.X));
        }
        while (!q.empty()) q.pop();
        for (int i = 0; i < m; i++)
            q.push(mp(d[i], d[i]));
        for (int i = 0; i < l; i++)
        {
            Pll tmp = q.top();
            q.pop();
            b[i] = tmp.X;
            q.push(mp(tmp.X + tmp.Y, tmp.X));
        }
        ll ans = 0;
        //for(int i = 0; i < l; i++) cout << a[i] << endl;
        for (int i = 0; i < l; i++)
            ans = max(ans, a[i] + b[l - i - 1]);
        printf("Case #%d: %lld\n", ++kase, ans);
    }
    return 0;
}
