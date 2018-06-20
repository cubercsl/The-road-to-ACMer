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

const int N = 1 << 18;
const int M = N + 10;
ll bit[M];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n, q;
    scanf("%d%d", &n, &q);
    vector<ll> a(n + 1);
    auto add = [&](int x, ll v) {
        for (int i = x; i < M; i += i & -i) bit[i] += v;
    };
    auto sum = [&](int x) {
        ll t = 0;
        for (int i = x; i; i -= i & -i) t += bit[i];
        return t;
    };
    auto query = [&](ll x) {
        if (bit[N] <= x) return INF;
        int p = 0;
        ll ret = 0;
        for (int i = 17; ~i; i--)
            if (ret + bit[p | (1 << i)] <= x) ret += bit[p | (1 << i)], p |= (1 << i);
        return p + 1;
    };
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &a[i]);
        add(i, a[i]);
    }
    while (q--)
    {
        static int pos;
        static ll val;
        scanf("%d%lld", &pos, &val);
        add(pos, val - a[pos]);
        a[pos] = val;
        ll tmp = a[1], ans = -1;
        if (tmp == 0)
        {
            puts("1");
            continue;
        }
        while (tmp < INF)
        {
            int k = query(tmp * 2 - 1);
            if (k == INF) break;
            if (sum(k - 1) == a[k])
            {
                ans = k;
                break;
            }
            tmp = sum(k - 1) + a[k];
        }
        printf("%lld\n", ans);
    }
    return 0;
}