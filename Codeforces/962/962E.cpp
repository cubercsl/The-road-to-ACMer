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

const int N = 1 << 19;
vector<int> P;
vector<int> R[N], B[N];

ll gao(ll L, ll R, VI& r, VI& b)
{
    ll ans = 0;
    if (L == -INF && R == INF)
    {
        if (!r.empty()) ans += r[r.size() - 1] - r[0];
        if (!b.empty()) ans += b[b.size() - 1] - b[0];
        return ans;
    }
    if (L == -INF)
    {
        if (!r.empty()) ans += R - r[0];
        if (!b.empty()) ans += R - b[0];
        return ans;
    }
    if (R == INF)
    {
        if (!r.empty()) ans += r[r.size() - 1] - L;
        if (!b.empty()) ans += b[b.size() - 1] - L;
        return ans;
    }
    ll rgap = 0, bgap = 0;
    int sz = r.size();
    if (sz == 0)
        rgap = R - L;
    else
    {
        rgap = max(r[0] - L, R - r[sz - 1]);
        for (int i = 1; i < sz; i++) rgap = max(rgap, (ll)r[i] - r[i - 1]);
    }
    sz = b.size();
    if (sz == 0)
        bgap = R - L;
    else
    {
        bgap = max(b[0] - L, R - b[sz - 1]);
        for (int i = 1; i < sz; i++) bgap = max(bgap, (ll)b[i] - b[i - 1]);
    }
    return min(2 * (R - L), 3 * (R - L) - rgap - bgap);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n;
    int x;
    char c;
    scanf("%d", &n);
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d %c", &x, &c);
        if (c == 'P') P.pb(x), cnt++;
        if (c == 'R') R[cnt].pb(x);
        if (c == 'B') B[cnt].pb(x);
    }
    ll ans = 0;
    P.pb(INF);
    ans += gao(-INF, P[0], R[0], B[0]);
    for (int i = 1; i < P.size(); i++) ans += gao(P[i - 1], P[i], R[i], B[i]);
    printf("%lld\n", ans);
    return 0;
}