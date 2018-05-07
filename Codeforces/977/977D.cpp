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

typedef unsigned long long ull;
vector<ull> a;
vector<ull> ans;
vector<vector<int> > G;
bool vis[100];
bool dfs(int u, int n)
{
    if (ans.size() == n)
    {
        for (auto& t : ans) cout << t << " ";
        return true;
    }
    for (auto& v : G[u])
    {
        if (!vis[v])
        {
            vis[v] = true;
            ans.push_back(a[v]);
            if (dfs(v, n)) return true;
            vis[v] = false;
            ans.pop_back();
        }
    }
    return false;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n;
    cin >> n;
    a.resize(n);
    for (auto& t : a) cin >> t;
    vector<int> in(n);
    G.resize(n), in.resize(n);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (a[i] * 2 == a[j])
                G[i].push_back(j), in[j]++;
            else if (a[i] % 3 == 0 && a[i] / 3 == a[j])
                G[i].push_back(j), in[j]++;
    for (int i = 0; i < n; i++)
    {
        if (!in[i])
        {
            ans.push_back(a[i]);
            if (dfs(i, n)) return 0;
            ans.pop_back();
        }
    }
    dfs(0, n);
    return 0;
}