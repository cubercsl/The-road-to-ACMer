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

const int N = 1e6 + 5;
int a[N], l[N], r[N];
int t[N];

inline void add(int x)
{
    for (int i = x; i < N; i += i & -i) t[i]++;
}

inline ll query(int x)
{
    ll ret = 0;
    for (int i = x; i; i -= i & -i) ret += t[i];
    return ret;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n;
    while (~scanf("%d", &n))
    {
        clr(t, 0);
        for (int i = 1; i <= n; i++) scanf("%d", a + i);
        stack<int> s;
        for (int i = 1; i <= n; i++)
        {
            while (!s.empty() && a[i] < a[s.top()]) r[s.top()] = i, s.pop();
            s.push(i);
        }
        while (!s.empty()) r[s.top()] = n + 1, s.pop();
        for (int i = n; i; i--)
        {
            while (!s.empty() && a[i] > a[s.top()]) l[s.top()] = i, s.pop();
            s.push(i);
        }
        while (!s.empty()) l[s.top()] = 0, s.pop();
        // for (int i = 1; i <= n; i++) printf("%d %d\n", l[i], r[i]);
        vector<PII> v;
        for (int i = 1; i <= n; i++) v.push_back({r[i], i});
        sort(v.begin(), v.end());
        ll ans = 1;
        int cur = 0;

        for (int i = 1; i <= n; i++)
        {
            while (cur < n && v[cur].X <= i)
                add(v[cur++].Y);
            ans += query(l[i]);
        }
        printf("%lld\n", ans);
    }
    return 0;
}