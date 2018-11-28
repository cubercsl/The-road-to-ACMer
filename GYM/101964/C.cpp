#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;
const int INF = 0x3f3f3f3f;
vector<int> G[maxn];
int dp[maxn][maxn];
int col[maxn];
int ans;
void work(vector<int> &ver, vector<int> &res, int i, int cnt, int val, int u)
{
    if (i >= ver.size())
    {

        if (dp[u][cnt] == -1) dp[u][cnt] = INF;
        dp[u][cnt] = min(dp[u][cnt], val);
        if (res.size() < 2) return;
        int n = res.size();
        vector<int> tmp = res;
        sort(tmp.begin(), tmp.end());
        ans = min(tmp[n - 1] + tmp[n - 2], ans);
        return;
    }
    int v = ver[i];
    for (int k = 0; dp[v][k] != -1; k++){
        res.push_back(dp[v][k]);
        work(ver, res,i + 1, cnt + k, max(val, dp[v][k]), u);
        res.pop_back();
    }
    
}
void update(int u, int fa)
{
    vector<int> ver, res;
    for (auto& v : G[u])
        if (v != fa) ver.push_back(v);
    work(ver,res, 0, 0, 0, u);
}
void dfs(int u, int fa)
{
    for (auto& v : G[u])
        if (v != fa) dfs(v, u);
    dp[u][0] = 0;
    if (col[u] == 1) dp[u][1] = 0;
    update(u, fa);
}
int main()
{
    memset(dp, -1, sizeof(dp));
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &col[i]);
    for (int i = 0, u, v; i < n - 1; i++)
    {
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    ans = INF;
}