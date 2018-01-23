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
bool vis[maxn];
int tot, prime[maxn];
void CalPhi(int n)
{
    clr(vis, 0);
    tot = 0;
    for (int i = 2; i < n; i++)
    {
        if (!vis[i])
            prime[tot++] = i;
        for (int j = 0; j < tot; j++)
        {
            if (i * prime[j] > n) break;
            vis[i * prime[j]] = 1;
            if (i % prime[j] == 0)
                break;
        }
    }
}

vector<PII> G[maxn];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    CalPhi(1 << 17);
    int n, m;
    cin >> n >> m;
    int num = *lower_bound(prime, prime + tot, n - 1);
    cout << num << " " << num << endl;
    for (int i = 1; i < n - 1; i++)
        G[i].pb(mp(i + 1, 1));
    G[n - 1].pb(mp(n, num - n + 2));
    m -= n - 1;
    bool flag = m != 0;
    for (int i = 1; i < n - 2 && flag; i++)
        for (int j = i + 2; j <= n; j++)
        {
            G[i].pb(mp(j, 1e7));
            if (--m == 0)
            {
                flag = false;
                break;
            }
        }
    for (int u = 1; u < n; u++)
        for (auto e : G[u])
            cout << u << " " << e.X << " " << e.Y << endl;

    return 0;
}
