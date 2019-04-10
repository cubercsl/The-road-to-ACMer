#include <bits/stdc++.h>
using namespace std;

const int N = 1 << 17;
vector<int> G[N];
int sz[N], sum[N], id[N], vis[N];

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0, s, r; i < n; i++)
    {
        scanf("%d%d", &s, &r);
        G[s].push_back(r);
    }
    for (int i = 1; i <= m; i++) sort(G[i].begin(), G[i].end(), greater<int>());
    for (int i = 1; i <= m; i++) id[i] = i, sz[i] = G[i].size();
    sort(id + 1, id + m + 1, [&](const int& x, const int& y) { return sz[x] < sz[y]; });
    int pos = 1, ans = 0, tmp = 0;
    for (int i = 1; i <= n; i++)
    {
        for (; (vis[id[pos]] || sz[id[pos]] < i) && pos <= m; pos++) tmp -= sum[id[pos]];
        for (int j = pos; j <= m; j++)
        {
            if (!vis[id[j]])
            {
                tmp += G[id[j]][i - 1];
                sum[id[j]] += G[id[j]][i - 1];
                if (sum[id[j]] < 0) tmp -= sum[id[j]], vis[id[j]] = 1, sum[id[j]] = 0;
            }
        }
        ans = max(ans, tmp);
    }
    printf("%d\n", ans);
}