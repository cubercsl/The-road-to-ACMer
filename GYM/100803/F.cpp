#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#define dbg(args...)                             \
    do                                           \
    {                                            \
        cout << "\033[32;1m" << #args << " -> "; \
        err(args);                               \
    } while (0)
#else
#define dbg(...)
#endif
void err()
{
    cout << "\033[39;0m" << endl;
}
template <template <typename...> class T, typename t, typename... Args>
void err(T<t> a, Args... args)
{
    for (auto x : a) cout << x << ' ';
    err(args...);
}
template <typename T, typename... Args>
void err(T a, Args... args)
{
    cout << a << ' ';
    err(args...);
}
/****************************************************************************************************/
const int maxn = 1e5;
const int N = 1 << 9;
bool vis[maxn];
int fa[N];
const int INF = 0x3f3f3f3f;
int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
void init(int n)
{
    for (int i = 0; i < n; i++) fa[i] = i;
}
void unite(int x, int y) { fa[find(x)] = find(y); }

int mst(int n, const vector<tuple<int, int, int>>& edges, int id = -1)
{
    init(n);
    int ans = 0, cnt = 0;
    for (int i = 0, u, v, w; i < edges.size(); i++)
    {
        if (i == id) continue;
        tie(w, u, v) = edges[i];
        if (find(u) == find(v)) continue;
        unite(u, v);
        ans += w;
        vis[i] = true;
        if (++cnt == n - 1) return ans;
    }
    return INF;
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    vector<tuple<int, int, int>> edges;
    for (int i = 0, u, v, w; i < m; i++)
    {
        scanf("%d%d%d", &u, &v, &w);
        --u, --v;
        edges.emplace_back(w, u, v);
    }
    sort(edges.begin(), edges.end());
    int ans = mst(n, edges);
    dbg(ans);
    int cnt = 0, sum = 0;
    for (int i = 0; i < m; i++){
        if (!vis[i]) continue;
        if (ans != mst(n, edges, i))
            cnt++, sum += get<0>(edges[i]);
    }
    printf("%d %d\n", cnt, sum);
    return 0;
}