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

const int N = 500005;
vector<int> G[N], H[N], S[N];
int dfn, in[N], out[N];
char s[N];
inline void init(int n)
{
    dfn = 0;
    for (int i = 0; i < n; i++)
        G[i].clear(), H[i].resize(1), S[i].resize(1);
}
void dfs(int u, int d)
{
    in[u] = ++dfn;
    int tmp = S[d].back();
    H[d].pb(dfn);
    S[d].pb(tmp ^ (1 << (s[u] - 'a')));
    for (auto v : G[u]) dfs(v, d + 1);
    out[u] = ++dfn;
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
        assert(n >= 1 && m >= 1);
        assert(n <= 500000 && m <= 500000);
        init(n);
        for (int i = 1; i < n; i++)
        {
            static int fa;
            scanf("%d", &fa);
            assert(fa >= 1 && fa < (i + 1));
            G[fa - 1].pb(i);
        }
        scanf("%s", s);
        dfs(0, 0);
        while (m--)
        {
            static int v, h;
            scanf("%d%d", &v, &h);
            assert(v >= 1 && h >= 1);
            assert(v <= n && h <= n);
            --v, --h;
            int l = lower_bound(H[h].begin(), H[h].end(), in[v]) - H[h].begin() - 1;
            int r = lower_bound(H[h].begin(), H[h].end(), out[v]) - H[h].begin() - 1;
            int t = S[h][l] ^ S[h][r];
            puts(t - (t & -t) ? "No" : "Yes");
        }
    }
    return 0;
}
