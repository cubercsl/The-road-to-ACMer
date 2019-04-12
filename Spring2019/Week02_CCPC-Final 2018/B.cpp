#include <bits/stdc++.h>
using namespace std;

const int N = 1 << 18;
vector<int> G[N];
int L[N], D[N];
int color[N];
vector<pair<int, int>> p[2];
const int INF = 0x3f3f3f3f;

bool dfs(int u, int c)
{
    color[u] = c;
    p[c].back().first = min(p[c].back().first, L[u]);
    p[c].back().second = max(p[c].back().second, L[u]);
    p[c ^ 1].back().first = min(p[c ^ 1].back().first, D[u]);
    p[c ^ 1].back().second = max(p[c ^ 1].back().second, D[u]);
    for (auto& v : G[u])
    {
        if (color[v] == c) return false;
        if (color[v] == -1 && !dfs(v, c ^ 1)) return false;
    }
    return true;
}

bool judge(int n)
{
    for (int i = 0; i < n; i++) color[i] = -1;
    for (int i = 0; i < n; i++)
        if (color[i] == -1)
        {
            p[0].emplace_back(INF, 0);
            p[1].emplace_back(INF, 0);
            if (!dfs(i, 1))
                return false;
        }
    return true;
}
namespace SegmentTree
{
#define lson o << 1
#define rson o << 1 | 1
#define Lson l, m, lson
#define Rson m + 1, r, rson
int val[N << 2];
void build(int l, int r, int o)
{
    if (l == r)
    {
        val[o] = 0;
        return;
    }
    const int m = l + r >> 1;
    build(Lson);
    build(Rson);
    val[o] = min(val[lson], val[rson]);
}

void update(int p, int v, int l, int r, int o)
{
    if (l == r)
    {
        val[o] = max(val[o], v);
        return;
    }
    const int m = l + r >> 1;
    if (p <= m)
        update(p, v, Lson);
    else
        update(p, v, Rson);
    val[o] = min(val[lson], val[rson]);
}
int ask() { return val[1]; }
}; // namespace SegmentTree

pair<int, int> dp[N][2];

struct Node
{
    int l, r;
    int id;
    Node(int l, int r, int id) : l(l), r(r), id(id) {}
    bool operator<(const Node& rhs) const
    {
        return r < rhs.r;
    }
};
using namespace SegmentTree;
int main()
{
    int T, kase = 0;
    scanf("%d", &T);
    while (T--)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; i++) G[i].clear();
        p[0].clear(), p[1].clear();
        for (int i = 0, u, v; i < m; i++)
        {
            scanf("%d%d", &u, &v);
            --u, --v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        for (int i = 0; i < n; i++) scanf("%d%d", &L[i], &D[i]);
        printf("Case %d: ", ++kase);
        if (!judge(n))
        {
            puts("IMPOSSIBLE");
            continue;
        }
        int sz = p[0].size();
        vector<Node> vec;
        for (int i = 0; i < sz; i++)
        {
            vec.emplace_back(p[0][i].first, p[0][i].second, i);
            vec.emplace_back(p[1][i].first, p[1][i].second, i);
        }
        sort(vec.begin(), vec.end());
        build(0, sz - 1, 1);
        int ans = INF;
        for (int i = 0; i < sz * 2;)
        {
            int j = i;
            while (j < sz * 2 && vec[j].r == vec[i].r) j++;
            for (int t = i; t < j; t++)
            {
                // cerr << '!' << vec[t].l << ' ' << vec[t].id << endl;
                update(vec[t].id, vec[t].l, 0, sz - 1, 1);
            }
            int t = ask();
            // cerr << t << endl;
            if (t != 0) ans = min(ans, vec[i].r - t);
            i = j;
        }
        printf("%d\n", ans);
    }
}