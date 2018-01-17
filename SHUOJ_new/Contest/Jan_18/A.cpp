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
const int maxn = 50;

struct Macth
{
    int n;
    vector<int> G[maxn];
    int linker[maxn];
    bool used[maxn];
    inline void init(int n)
    {
        this->n = n;
        for (int i = 0; i < n; i++) G[i].clear();
    }
    inline void addedge(int u, int v) { G[u].pb(v); }
    bool dfs(int u)
    {
        for (int i = 0; i < G[u].size(); i++)
        {
            int v = G[u][i];
            if (!used[v])
            {
                used[v] = true;
                if (linker[v] == -1 || dfs(linker[v]))
                {
                    linker[v] = u;
                    return true;
                }
            }
        }
        return false;
    }
    int MaxMatch()
    {
        int ans = 0;
        clr(linker, -1);
        for (int u = 0; u < n; u++)
        {
            clr(used, 0);
            if (dfs(u)) ans++;
        }
        return ans;
    }
} gao;

const int N = 50;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        int a[N], b[N], p[N];
        cin >> n;
        gao.init(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> p[i];
        int m;
        cin >> m;
        for (int i = 0; i < m; i++) cin >> b[i];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (p[i] >= abs(a[i] - b[j])) gao.addedge(i, j);
        cout << gao.MaxMatch() << endl;
    }
    return 0;
}
