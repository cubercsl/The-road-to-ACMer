#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int INF = 0x3f3f3f3f;
const int N = 1 << 18;
int c[N], a[N];
int vis[N];
int dfs(int u, int f)
{
    if (vis[u]) return INF;
    vis[u] = f;
    int ret = INF;
    if (vis[a[u]] == f)
    {
        ret = c[u];
        for (int i = a[u]; i != u; i = a[i]) ret = min(ret, c[i]);
    }
    return min(ret, dfs(a[u], f));
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &c[i]);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]), --a[i];
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        int tmp = dfs(i, i + 1);
        if (tmp != INF) ans += tmp;
    }
    printf("%lld\n", ans);
}