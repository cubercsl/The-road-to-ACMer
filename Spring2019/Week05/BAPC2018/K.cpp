#include <bits/stdc++.h>
using namespace std;

const int maxn = 1 << 17;
int d[maxn];

struct BCC
{
    vector<int> G[maxn];
    int pre[maxn], lowlink[maxn], sccno[maxn], dfs_clock, scc_cnt;
    stack<int> S;
    void init(int n)
    {
        for (int i = 0; i < n; i++) G[i].clear();
    }
    inline void add_edge(int u, int v) { G[u].push_back(v); }
    void dfs(int u, int fa)
    {
        pre[u] = lowlink[u] = ++dfs_clock;
        S.push(u);
        int cnt = 0;
        for (auto& v : G[u])
        {
            if (v == fa && !cnt)
            {
                cnt++;
                continue;
            }
            if (!pre[v])
            {
                dfs(v, u);
                lowlink[u] = min(lowlink[u], lowlink[v]);
            }
            else if (!sccno[v])
                lowlink[u] = min(lowlink[u], pre[v]);
        }
        if (lowlink[u] == pre[u])
        {
            scc_cnt++;
            for (;;)
            {
                int x = S.top();
                S.pop();
                sccno[x] = scc_cnt;
                if (x == u) break;
            }
        }
    }
    void find_scc(int n)
    {
        dfs_clock = 0, scc_cnt = 0;
        memset(sccno, 0, sizeof(int) * n), memset(pre, 0, sizeof(int) * n);
        for (int i = 0; i < n; i++)
            if (!pre[i]) dfs(i, -1);
    }
} gao;

vector<pair<int, int>> edges;
int main()
{
    int n, h;
    scanf("%d%d", &n, &h);
    for (int i = 1, a, b; i < n; i++)
    {
        scanf("%d%d", &a, &b);
        d[a]++, d[b]++;
        edges.emplace_back(a, b);
    }
    vector<int> leaf;
    for (int i = 0; i < n; i++)
        if (d[i] == 1)
            leaf.push_back(i);
    bool flag = false;
    do
    {
        if (flag) leaf.pop_back();
        random_shuffle(leaf.begin(), leaf.end());
        if (leaf.size() & 1) leaf.push_back(leaf[0]), flag = true;
        gao.init(n);
        for (auto& [u, v] : edges) gao.add_edge(u, v), gao.add_edge(v, u);
        for (int i = 0; i < leaf.size(); i += 2)
        {
            gao.add_edge(leaf[i], leaf[i + 1]);
            gao.add_edge(leaf[i + 1], leaf[i]);
        }
        gao.find_scc(n);
        // printf("%d\n", gao.scc_cnt);
    } while (gao.scc_cnt != 1);
    printf("%d\n", leaf.size() / 2);
    for (int i = 0; i < leaf.size(); i += 2) printf("%d %d\n", leaf[i], leaf[i + 1]);
}