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

const int N = 1 << 17;
vector<int> G[N];
bool vis[N][2];
int fa[N][2];
void dfs(int u, int d, int pre)
{
    if (vis[u][d]) return;
    vis[u][d] = 1;
    fa[u][d] = pre;
    for (auto& v : G[u]) dfs(v, d ^ 1, u);
}

void dfs2(int u, int d)
{
    if (!u) return;
    dfs2(fa[u][d], d ^ 1);
    cout << u << " ";
}

int vv[N];
bool dfs3(int u)
{
    vv[u] = 1;
    for (auto& v : G[u])
        if (vv[v] == 1 || vv[v] == 0 && dfs3(v)) return true;
    vv[u] = 2;
    return false;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        static int t;
        cin >> t;
        while (t--)
        {
            static int j;
            cin >> j;
            G[i].push_back(j);
        }
    }
    int s;
    cin >> s;
    dfs(s, 0, 0);
    for (int i = 1; i <= n; i++)
    {
        if (vis[i][1] && G[i].size() == 0)
            return cout << "Win" << endl, dfs2(i, 1), 0;
    }
    if (dfs3(s))
        cout << "Draw" << endl;
    else
        cout << "Lose" << endl;
    return 0;
}