#include <bits/stdc++.h>
using namespace std;

const int N = 1 << 18;
const int INF = 0x3f3f3f3f;
const char* res[] = {"Sheep", "Panda"};

vector<int> G[N];
vector<int> black;
vector<int> circle, black_in_circle;
int sum[N], disa[N], disb[N];
bool vis[N], in_circle[N];
int circle_start;
void init(int n)
{
    for (int i = 1; i <= n; i++) G[i].clear();
    black.clear();
    circle.clear();
    black_in_circle.clear();
    memset(sum, 0, sizeof(int) * (n + 1));
    memset(disa, -1, sizeof(int) * (n + 1));
    memset(disb, -1, sizeof(int) * (n + 1));
    memset(vis, 0, sizeof(bool) * (n + 1));
    memset(in_circle, 0, sizeof(bool) * (n + 1));
}

void bfs(int s, int d[])
{
    queue<int> q;
    d[s] = 0;
    q.push(s);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (auto&& v : G[u])
        {
            if (~d[v]) continue;
            d[v] = d[u] + 1;
            q.push(v);
        }
    }
}

bool dfs(int u, int fa = 0)
{
    vis[u] = 1;
    for (auto&& v : G[u])
    {
        if (v == fa) continue;
        if (vis[v])
        {
            circle_start = v;
            circle.push_back(u);
            return true;
        }
        else if (dfs(v, u))
        {
            circle.push_back(u);
            return u != circle_start;
        }
    }
    return false;
}

void accumulate(int u, int fa = 0)
{
    for (auto&& v : G[u])
    {
        if (v == fa || in_circle[v]) continue;
        accumulate(v, u);
        sum[u] += sum[v];
    }
}

inline int getdis(int a, int b, int c) { return min((a - b + c) % c, (b - a + c) % c); }

bool solve()
{
    circle_start = 0;
    dfs(1);
    for (auto&& it : circle) in_circle[it] = true;
    pair<int, int> za = {INF, 0}, zb = {INF, 0};
    for (int i = 0; i < circle.size(); i++)
    {
        auto&& it = circle[i];
        za = min(za, {disa[it], i});
        zb = min(zb, {disb[it], i});
    }
    int &x = za.second, &y = zb.second;
    if (za.first <= zb.first || sum[circle[x]]) return false;

    for (auto&& it : circle)
    {
        accumulate(it);
        if (sum[it] > 0) black_in_circle.push_back(it);
    }
    int l = -1, r = -1;
    for (int i = x; i != y; i++)
    {
        if (i == circle.size()) i = 0;
        if (sum[circle[i]])
        {
            l = i;
            break;
        }
    }
    for (int i = x - 1; i != y; i--)
    {
        if (i == -1) i = circle.size() - 1;
        if (sum[circle[i]])
        {
            r = i;
            break;
        }
    }
    if (l == r || l == -1 || r == -1) return false;
    int sz = circle.size();
    int k = za.first - zb.first;
    if (getdis(x, y, sz) < k) return false;
    if (getdis(l, y, sz) + getdis(l, r, sz) < k + getdis(x, r, sz)) return false;
    if (getdis(r, y, sz) + getdis(l, r, sz) < k + getdis(x, l, sz)) return false;
    int d = min(getdis(x, l, sz), getdis(x, r, sz));
    for (int i = 0; i < circle.size(); i++)
    {
        int da = getdis(i, l, sz);
        int db = getdis(i, r, sz);
        int dc = getdis(i, y, sz);
        if (max(da, db) < d && dc <= k) return false;
    }
    return true;
}

int main()
{
    int T;
    scanf("%d", &T);
    for (int t = 0; t < T; t++)
    {
        int n;
        scanf("%d", &n);
        init(n);
        for (int i = 0, u, v; i < n; i++)
        {
            scanf("%d%d", &u, &v);
            G[u].push_back(v);
            G[v].push_back(u);
        }
        int m;
        scanf("%d", &m);
        for (int i = 0, x; i < m; i++)
        {
            scanf("%d", &x);
            sum[x] = 1;
            black.push_back(x);
        }
        int pa, pb;
        scanf("%d%d", &pa, &pb);
        bfs(pa, disa);
        bfs(pb, disb);
        bool win = false;
        for (auto&& it : black)
        {
            if (disa[it] <= disb[it])
            {
                win = true;
                break;
            }
        }
        if (!win) win = solve();
        printf("Case %d: %s\n", t + 1, res[win]);
    }
}