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

const int N = 25;
bool G[N][N];
int f[N];
int id[N];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) id[i] = i;
    for (int i = 1; i <= n; i++) cin >> f[i];
    int q;
    cin >> q;
    while (q--)
    {
        static int op;
        cin >> op;
        if (op == 1)
        {
            static int x, l, r;
            cin >> x >> l >> r;
            for (int i = l; i <= r; i++) G[id[x]][id[i]] = 1;
        }
        else
        {
            static int x, v;
            cin >> x >> v;
            f[++n] = v;
            id[x] = n;
        }
    }
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                G[i][j] |= (G[i][k] & G[k][j]);
    ll ans = 1e18;
    for (int i = 1; i <= n; i++)
    {
        ll tmp = f[i];
        for (int j = 1; j <= n; j++)
            if (G[i][j] && i != j) tmp += f[j];
        ans = min(ans, tmp);
    }
    cout << ans << endl;
    return 0;
}
