#include <bits/stdc++.h>
using namespace std;

const int N = 1 << 18;
typedef pair<int, int> PII;
int a[N];
int id[N << 2], pos[N << 2];
int n;
vector<int> G[N << 2];
int deg[N << 2];

inline void init(int n)
{
    memset(deg, 0, sizeof(int) * (n << 2 | 5));
    for (int i = 0; i < (n << 2 | 5); i++) G[i].clear();
}

inline void addedge(int u, int v)
{
    G[u].push_back(v);
    ++deg[v];
}

#define lson o << 1
#define rson o << 1 | 1
#define Lson l, m, lson
#define Rson m + 1, r, rson
void build(int l = 0, int r = n - 1, int o = 1)
{
    id[o] = -1;
    if (l == r)
    {
        pos[l] = o, id[o] = l;
        return;
    }
    int m = l + r >> 1;
    addedge(lson, o);
    addedge(rson, o);
    build(Lson);
    build(Rson);
}

void Addedge(int L, int R, int p, int l = 0, int r = n - 1, int o = 1)
{
    // cerr << "[" << L << ", " << R << "]" << id[p] << endl;
    if (L <= l && r <= R)
    {
        addedge(o, p);
        return;
    }
    int m = l + r >> 1;
    if (L <= m) Addedge(L, R, p, Lson);
    if (m < R) Addedge(L, R, p, Rson);
}

inline void topo()
{
    priority_queue<PII, vector<PII>, greater<PII>> q;
    for (int i = 0; i < n; i++)
        if (!deg[pos[i]]) q.push({a[i], pos[i]});
    vector<int> ans;
    while (!q.empty())
    {
        PII cur = q.top();
        q.pop();
        int u = cur.second;
        if (~cur.first) ans.push_back(cur.first);
        for (auto& v : G[u])
            if (--deg[v] == 0) q.push({~id[v] ? a[id[v]] : -1, v});
    }
    int m = ans.size();
    for (int i = 0; i < m; i++) printf("%d%c", ans[i], " \n"[i == m - 1]);
}

int main()
{
    scanf("%d", &n);
    init(n);
    for (int i = 0; i < n; i++) scanf("%d", a + i);
    build();
    for (int i = 0; i < n; i++)
        if (~a[i])
        {
            int s = a[i] % n, t = i;
            if (s == t) continue;
            if (s < t)
                Addedge(s, t - 1, pos[i]);
            else
            {
                if (t) Addedge(0, t - 1, pos[i]);
                Addedge(s, n - 1, pos[i]);
            }
        }
    topo();
}