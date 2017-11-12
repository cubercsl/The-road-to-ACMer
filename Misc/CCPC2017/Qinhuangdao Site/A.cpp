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
int t[maxn], s[maxn];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int T;
    scanf("%d", &T);
    while (T--)
    {
        static int n, m, p;
        scanf("%d%d%d", &n, &m, &p);
        for (int i = 0; i < n; i++)
        {
            scanf("%d", s + i);
            --s[i];
        }
        for (int i = 0; i < p; i++)
        {
            static int a, b;
            scanf("%d%d", &a, &b);
            t[i] = (s[a - 1] - b % m + m) % m;
        }
        sort(t, t + p);
        ll tmp = 0;
        for (int i = 0; i < p; i++)
            tmp += t[i] - t[0];
        ll ans = tmp;
        for (int i = 1; i < p; i++)
        {
            tmp += m - (ll)p * (ll)(t[i] - t[i - 1]);
            ans = min(ans, tmp);
        }
        printf("%lld\n", ans);
    }
    return 0;
}
