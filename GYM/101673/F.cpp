#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e4 + 5;
ll sz[maxn];
vector<int> G[maxn];
ll ans1, ans2;
ll dfs_cnt(int u, int fa)
{
    sz[u] = 1;
    for (auto& v : G[u])
        if (v != fa) sz[u] += dfs_cnt(v, u);
    return sz[u];
}
void dfs(int u, int fa)
{
    vector<ll> num;
    long long tmp = sz[1] - sz[u];
    num.push_back(sz[1] - sz[u]);
    for (auto& v : G[u])
        if (v != fa) num.push_back(sz[v]), tmp += sz[v];
    tmp *= tmp;
    for (int i = 0; i < num.size(); i++)
        tmp -= 1LL * num[i] * num[i];
    tmp /= 2;
    if (tmp > ans1)
    {
        ans1 = tmp;
        sort(num.begin(), num.end(), greater<int>());
        if (num.size() > 1)
        {
            tmp = num[0] * num[1];
            ans2 = ans1 - tmp;
        }
        else
            ans2 = ans1;
    }
    for (auto& v : G[u])
        if (v != fa) dfs(v, u);
}
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0, u, v; i < n; i++)
    {
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs_cnt(1, -1);
    ans1 = 0;
    dfs(1, -1);
    printf("%lld %lld\n", ans1, ans2);
}