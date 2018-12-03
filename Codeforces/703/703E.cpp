#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1 << 17;
int f[N][35], w[N];
ll dp[N][35][2];

pair<ll, ll> ask(int u, ll k)
{
    ll s = 0, m = 1e18;
    for (int i = 34; ~i; i--)
    {
        if (k >> i & 1)
        {
            s += dp[u][i][0];
            m = min(m, dp[u][i][1]);
            u = f[u][i];
        }
    }
    return {s, m};
}

int main()
{
    int n;
    ll k;
    scanf("%d%lld", &n, &k);
    for (int i = 0; i < n; i++) scanf("%d", &f[i][0]);
    for (int i = 0; i < n; i++) scanf("%d", &w[i]);
    for (int i = 0; i < n; i++) dp[i][0][0] = dp[i][0][1] = w[i];
    for (int j = 1; j < 35; j++)
        for (int i = 0; i < n; i++)
        {
            f[i][j] = f[f[i][j - 1]][j - 1];
            dp[i][j][0] = dp[i][j - 1][0] + dp[f[i][j - 1]][j - 1][0];
            dp[i][j][1] = min(dp[i][j - 1][1], dp[f[i][j - 1]][j - 1][1]);
        }
    for (int i = 0; i < n; i++)
    {
        auto ans = ask(i, k);
        printf("%lld %lld\n", ans.first, ans.second);
    }
}