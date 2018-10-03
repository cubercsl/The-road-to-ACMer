#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
constexpr int N = 1 << 18;
constexpr int mod = 1e9 + 7;

// slieve
int primes[N], phi[N], mu[N], cnt = 0;
ll inv[N];
bool vis[N];
vector<int> factor[N];

void init()
{
    phi[1] = 1, mu[1] = 1;
    for (int i = 2; i < N; i++)
    {
        if (!vis[i]) primes[cnt++] = i, phi[i] = i - 1, mu[i] = -1;
        for (int j = 0; j < cnt && i * primes[j] < N; j++)
        {
            int t = i * primes[j];
            vis[t] = true;
            if (i % primes[j] == 0)
            {
                phi[t] = phi[i] * primes[j];
                mu[t] = 0;
                break;
            }
            else
                phi[t] = phi[i] * phi[primes[j]], mu[t] = -mu[i];
        }
    }

    for (int i = 1; i < N; ++i)
        for (int j = i; j < N; j += i)
            factor[j].push_back(i);

    inv[1] = 1;
    for (int i = 2; i < N; ++i) inv[i] = ((-(mod / i) * inv[mod % i] % mod) + mod) % mod;
}

int a[N], id[N];

// lca
vector<int> G[N], vec[N], sp;
int dep[N], dfn[N];
pair<int, int> dp[21][N << 1];
void dfs(int u, int fa)
{
    for (auto& d : factor[a[u]]) vec[d].push_back(u);
    dfn[u] = sp.size();
    sp.push_back(u);
    for (auto& v : G[u])
    {
        if (v == fa) continue;
        dep[v] = dep[u] + 1;
        dfs(v, u);
        sp.push_back(u);
    }
}
void initrmq()
{
    int n = sp.size();
    for (int i = 0; i < n; i++) dp[0][i] = {dfn[sp[i]], sp[i]};
    for (int i = 1; (1 << i) <= n; i++)
        for (int j = 0; j + (1 << i) - 1 < n; j++)
            dp[i][j] = min(dp[i - 1][j], dp[i - 1][j + (1 << (i - 1))]);
}
int lca(int u, int v)
{
    int l = dfn[u], r = dfn[v];
    if (l > r) swap(l, r);
    int k = __lg(r - l + 1);
    return min(dp[k][l], dp[k][r - (1 << k) + 1]).second;
}

// vtree
vector<int> vtree[N];

void build(vector<int>& vec)
{
    sort(vec.begin(), vec.end(), [&](int x, int y) { return dfn[x] < dfn[y]; });
    static int s[N];
    int top = 0;
    s[top] = 0;
    vtree[0].clear();
    for (auto& u : vec)
    {
        int vlca = lca(u, s[top]);
        vtree[u].clear();
        if (vlca == s[top])
            s[++top] = u;
        else
        {
            while (top && dep[s[top - 1]] >= dep[vlca])
            {
                vtree[s[top - 1]].push_back(s[top]);
                top--;
            }
            if (s[top] != vlca)
            {
                vtree[vlca].clear();
                vtree[vlca].push_back(s[top--]);
                s[++top] = vlca;
            }
            s[++top] = u;
        }
    }
    for (int i = 0; i < top; ++i) vtree[s[i]].push_back(s[i + 1]);
}

// vtree dp
ll s[N];
ll go(int u, int d)
{
    ll ret1 = 0, ret2 = 0;
    s[u] = a[u] % d == 0 ? phi[a[u]] : 0;
    for (auto& v : vtree[u])
    {
        (ret1 += go(v, d)) %= mod;
        (ret2 += (s[v] * s[u]) % mod) %= mod;
        (s[u] += s[v]) %= mod;
    }
    ret2 = ret2 * -4 % mod * dep[u] % mod;
    if (a[u] % d == 0) (ret2 += (ll)phi[a[u]] * phi[a[u]] % mod * -2 * dep[u] % mod) %= mod;
    return (ret1 + ret2 + mod) % mod;
}

void debug()
{
    for (int i = 0; i <= 3; i++)
    {
        printf("[%d] -> ", i);
        for (auto& v : vtree[i]) printf(" %d", v);
        puts("");
    }
}

ll solve(int d)
{
    ll ans = 0, sum = 0;
    for (auto& id : vec[d]) (sum += phi[a[id]]) %= mod;
    for (auto& id : vec[d]) (ans += sum * phi[a[id]] % mod * dep[id] % mod) %= mod;
    ans = ans * 2 % mod;
    build(vec[d]);
    // debug();
    (ans += go(0, d)) %= mod;
    return (ans + mod) % mod;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    init();

    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]), id[a[i]] = i;
    for (int i = 1, u, v; i < n; i++)
    {
        scanf("%d%d", &u, &v);
        G[u].push_back(v), G[v].push_back(u);
    }
    G[0].push_back(1), G[1].push_back(0);

    dfs(0, -1);
    initrmq();

    static ll f[N];
    for (int i = 1; i <= n; i++) f[i] = solve(i);

    ll ans = 0;

    for (int d = 1; d <= n; d++)
    {
        ll g = 0;
        for (int x = d; x <= n; x += d)
            (g += (mu[x / d] * f[x]) % mod) %= mod;
        (ans += g * d % mod * inv[phi[d]] % mod) %= mod;
    }

    ans = ans * inv[n] % mod * inv[n - 1] % mod;

    printf("%lld\n", ans);
}