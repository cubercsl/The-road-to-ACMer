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

#define lson rt << 1
#define rson rt << 1 | 1

const int N = 2e6 + 5;
vector<ll> G[N];
vector<ll> pre[N];
int d[N];

void dfs(int rt, const int& n)
{
    if (rt > n) return;
    dfs(lson, n);
    dfs(rson, n);
    int pl = 0, pr = 0;
    vector<ll>&A = G[lson], &B = G[rson], &C = G[rt];
    int a = d[lson], b = d[rson];
    int sl = A.size(), sr = B.size();
    C.pb(0);
    while (pl < sl && pr < sr)
    {
        if (A[pl] + a < B[pr] + b)
            C.pb(A[pl++] + a);
        else
            C.pb(B[pr++] + b);
    }
    while (pl < sl) C.pb(A[pl++] + a);
    while (pr < sr) C.pb(B[pr++] + b);
    pre[rt].pb(0);
    for (int i = 1; i < C.size(); i++)
        pre[rt].pb(pre[rt][i - 1] + C[i]);
}

ll calc(int a, int h, const int& n)
{
    if (h < 0 || a > n || a == 0) return 0;
    int pos = upper_bound(G[a].begin(), G[a].end(), h) - G[a].begin() - 1;
    if (~pos)
        return (ll)h * (pos + 1) - pre[a][pos];
    return 0;
}

ll solve(int a, int h, const int& n)
{
    ll ans = 0;
    ans += calc(a, h, n);
    while (a > 1 && (h -= d[a]) > 0)
    {
        ans += h;
        ans += calc(a ^ 1, h - d[a ^ 1], n);
        a >>= 1;
    }
    return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n, m;
    while (~scanf("%d%d", &n, &m))
    {
        for (int i = 1; i <= n; i++)
            G[i].clear(), pre[i].clear();
        for (int i = 1; i < n; i++)
            scanf("%d", &d[i + 1]);
        dfs(1, n);
        while (m--)
        {
            static int a, h;
            scanf("%d%d", &a, &h);
            printf("%lld\n", solve(a, h, n));
        }
    }
    return 0;
}
