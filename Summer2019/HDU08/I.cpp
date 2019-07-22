#include <bits/stdc++.h>
using namespace std;

const int maxn = 1005;
const int INF = 0x3f3f3f3f;
struct MDST
{
    int n;
    int w[maxn][maxn];
    int vis[maxn];
    int ans;
    int removed[maxn];
    int cid[maxn];
    int pre[maxn];
    int iw[maxn];
    int max_cid;
    void init(int n)
    {
        this->n = n;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) w[i][j] = INF;
    }
    void AddEdge(int u, int v, int cost)
    {
        w[u][v] = min(w[u][v], cost);
    }
    int dfs(int s)
    {
        vis[s] = 1;
        int ans = 1;
        for (int i = 0; i < n; i++)
            if (!vis[i] && w[s][i] < INF) ans += dfs(i);
        return ans;
    }
    bool cycle(int u)
    {
        max_cid++;
        int v = u;
        while (cid[v] != max_cid)
        {
            cid[v] = max_cid;
            v = pre[v];
        }
        return v == u;
    }
    void update(int u)
    {
        iw[u] = INF;
        for (int i = 0; i < n; i++)
            if (!removed[i] && w[i][u] < iw[u])
            {
                iw[u] = w[i][u];
                pre[u] = i;
            }
    }
    bool solve(int s)
    {
        memset(vis, 0, sizeof(vis));
        if (dfs(s) != n) return false;
        memset(removed, 0, sizeof(removed));
        memset(cid, 0, sizeof(cid));
        for (int u = 0; u < n; u++) update(u);
        pre[s] = s;
        iw[s] = 0;
        ans = max_cid = 0;
        for (;;)
        {
            bool have_cycle = false;
            for (int u = 0; u < n; u++)
                if (u != s && !removed[u] && cycle(u))
                {
                    have_cycle = true;
                    int v = u;
                    do
                    {
                        if (v != u) removed[v] = 1;
                        ans += iw[v];
                        for (int i = 0; i < n; i++)
                            if (cid[i] != cid[u] && !removed[i])
                            {
                                if (w[i][v] < INF)
                                    w[i][u] = min(w[i][u], w[i][v] - iw[v]);
                                w[u][i] = min(w[u][i], w[v][i]);
                                if (pre[i] == v) pre[i] = u;
                            }
                        v = pre[v];
                    } while (v != u);
                    update(u);
                    break;
                }
            if (!have_cycle) break;
        }
        for (int i = 0; i < n; i++)
            if (!removed[i]) ans += iw[i];
        return true;
    }
} gao;

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n, m;
        scanf("%d%d", &n, &m);

        gao.init(n);
        for (int i = 0, u, v, w; i < m; i++)
        {
            scanf("%d%d%d", &u, &v, &w);
            --u, --v;
            w = -w * 1000;
            if (v == n - 1) w = w + u;
            gao.AddEdge(u, v, w);
        }
        gao.solve(0);
        int ans = gao.ans;
        printf("%d %d\n", (-ans + 999) / 1000, (-ans + 999) / 1000 * 1000 + ans + 1);
    }
}