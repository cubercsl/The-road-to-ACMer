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

const int N = 105;
vector<int> G[N];
bool vis[N];
void dfs(int u)
{
    if (vis[u]) return;
    vis[u] = 1;
    for (auto& v : G[u]) dfs(v);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    if (n != m) return cout << "NO" << endl, 0;
    while (m--)
    {
        static int u, v;
        cin >> u >> v;
        G[u].pb(v);
        G[v].pb(u);
    }
    dfs(1);
    for (int i = 1; i <= n; i++)
        if (!vis[i]) return cout << "NO" << endl, 0;
    cout << "FHTAGN!" << endl;
    return 0;
}
