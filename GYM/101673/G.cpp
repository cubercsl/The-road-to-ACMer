#include <bits/stdc++.h>
using namespace std;
const int maxn = 2000;
typedef long long ll;
ll dp[maxn][maxn];
ll a[maxn], b[maxn];
int cnt,n,m;
ll dfs(int u,int k){
    if (u > n) return 0;
    if (dp[u][k] != -1) return dp[u][k];
    return dp[u][k] = max(dfs(u + 1, max(1, k - 1)), dfs(u + 1, min(k + 1, cnt - 1)) + min(a[u], b[k]));
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%lld", a + i);
    b[1] = m;
    for (cnt = 2; b[cnt - 1] != 0; cnt++)
        b[cnt] = b[cnt - 1] * 2 / 3;
    memset(dp, -1, sizeof(dp));
    printf("%lld\n", dfs(1, 1));
}