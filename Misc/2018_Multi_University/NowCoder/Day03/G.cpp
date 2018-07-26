// ybmj
#include <bits/stdc++.h>
using namespace std;
#define lson (rt << 1)
#define rson (rt << 1 | 1)
#define lson_len (len - (len >> 1))
#define rson_len (len >> 1)
#define pb(x) push_back(x)
#define clr(a, x) memset(a, x, sizeof(a))
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
const int INF = 0x3f3f3f3f;
const int NINF = 0xc0c0c0c0;
const int mod = 1e9 + 7;
const int maxn = 5e3 + 5;
ll dep[maxn], dp[maxn];
bool vis[maxn];
vector<int> G[maxn];
ll n, K, D;
 
void dfs_dep(int u, int fa, int d) {
    dep[u] = d;
    for (auto &v : G[u])
        if (v != fa) dfs_dep(v, u, d + 1);
}
ll dfs_sz(int u, int fa, int i, int d) {
    if (d >= D - 1 || u == -1) return 0;
    ll ret = 1;
    for (auto &v : G[u]) {
        if (v != fa && (dep[v] < dep[i] || (dep[v] == dep[i] && vis[v])))
            ret += dfs_sz(v, u, i, d + 1);
    }
    return ret;
}
 
ll dfs(int u, int fa) {
    ll ret = K - dfs_sz(fa, u, u, 0);
    if (ret <= 0) return NINF;
    vis[u] = 1;
    for (auto &v : G[u])
        if (v != fa) {
            ll foo = dfs(v, u);
            if (foo <= 0) return NINF;
            ret = ret * foo % mod;
        }
    return ret;
}
int main() {
// /*
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    // */
    std::ios::sync_with_stdio(false);
    cin >> n >> K >> D;
    for (int i = 0, u, v; i < n - 1; i++) {
        cin >> u >> v;
        G[u].pb(v);
        G[v].pb(u);
    }
    dfs_dep(1, -1, 0);
    ll ans = dfs(1, -1);
    if (ans <= 0) {
        cout << 0 << endl;
        return 0;
    }
    D++;
    clr(vis, 0);
    ll foo = dfs(1, -1);
    if (foo <= 0) foo = 0;
    ans = (ans - foo + mod) % mod;
    cout << ans << endl;
}