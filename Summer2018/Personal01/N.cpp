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

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    fastin
    int n, m;
    cin >> n >> m;
    vector<VI> G(n + 1);
    vector<VI> vis(n + 1, VI(2)), fa(n + 1, VI(2));
    vector<int> col(n + 1);
    function<void(int, bool, int)> dfs = [&](int u, int d, int p) {
        if (vis[u][d]) return;
        vis[u][d] = 1;
        fa[u][d] = p;
        for (auto& v : G[u])
            dfs(v, d ^ 1, u);
    };
    function<void(int, bool)> print = [&](int u, bool d) {
        if (!u) return;
        print(fa[u][d], d ^ 1);
        cout << u << " ";
    };
    function<bool(int)> check = [&](int u) {
        col[u] = 1;
        for (auto& v : G[u])
            if (col[v] == 1 || col[v] == 0 && check(v)) return true;
        col[u] = 2;
        return false;
    };
    for (int i = 1; i <= n; i++)
    {
        static int x;
        cin >> x;
        for (int j = 0, k; j < x; j++)
        {
            cin >> k;
            G[i].push_back(k);
        }
    }
    int s;
    cin >> s;
    dfs(s, 0, 0);
    for (int i = 1; i <= n; i++)
    {
        if (G[i].size() == 0 && vis[i][1])
        {
            cout << "Win" << endl;
            print(i, 1);
            return 0;
        }
    }
    if (check(s))
        cout << "Draw";
    else
        cout << "Lose";
    return 0;
}
