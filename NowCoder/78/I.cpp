#include <bits/stdc++.h>
using namespace std;
#define clr(a, x) memset(a, x, sizeof(a))
#define mp(x, y) make_pair(x, y)
#define pb(x) push_back(x)
#define X first
#define Y second
#define fastin                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef pair<int, int> PII;
typedef vector<int> VI;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-6;

const int N = 1e5 + 7;

vector<PII> G[N];
int Index = 0;
int cnt = 0;
int dfn[N], low[N], instack[N];
stack<int> st;
int belong[N];
int n;
void init()
{
    for (int i = 0; i < N; i++)
        G[i].clear();
    Index = 0;
    cnt = 0;
    clr(dfn, 0);
    while (!st.empty())
        st.pop();
    clr(instack, 0);
}
void tarjan(int u)
{
    dfn[u] = low[u] = ++Index;
    st.push(u);
    instack[u] = 1;
    for (auto temp : G[u])
    {
        vector<int> edge{temp.X, temp.Y};
        for (int i = 0; i < 2; i++)
        {
            int v = edge[i];
            if (!dfn[v])
            {
                tarjan(v);
                low[u] = min(low[u], low[v]);
            }
            else if (instack[v])
                low[u] = min(low[u], dfn[v]);
        }
    }
    int x;
    if (dfn[u] == low[u])
    {
        cnt++;
        do
        {
            x = st.top();
            st.pop();
            instack[x] = 0;
            belong[x] = cnt;
        } while (x != u);
    }
}
void solve()
{
    for (int i = 1; i <= n; i++)
        if (!dfn[i])
            tarjan(i);
}

vector<PII> VG[N];
bool has[N];
int deg[N];
bool met[N];
void dfs(int u, int flag)
{
    if (met[u] && has[u])
        return;
    if (flag)
        has[u] = 1;
    if (has[u])
        flag = 1;
    met[u] = 1;
    if (!has[u] && !flag)
    {
        for (auto temp : VG[u])
        {
            if (temp.X == -1 || temp.Y == -1)
                continue;
            dfs(temp.X, 0);
            dfs(temp.Y, 0);
            if (has[temp.X] && has[temp.Y])
            {
                flag = 1, has[u] = 1;
                break;
            }
        }
    }
    if (flag)
    {
        for (auto temp : VG[u])
        {
            if (temp.X != -1)
                dfs(temp.X, 1);
            if (temp.Y != -1)
                dfs(temp.Y, 1);
        }
    }
}
void init_ans()
{
    memset(met, 0, sizeof(met));
    for (int i = 1; i <= cnt; i++)
        if (!deg[i])
            dfs(i, has[i]);
    for (int i = 1; i <= cnt; i++)
        if (!met[i])
            dfs(i, has[i]);
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif

    fastin int m, k, q;
    while (cin >> n >> m >> k >> q)
    {
        init();
        for (int i = 0; i < m; i++)
        {
            int a, b, c;
            cin >> a >> b >> c;
            G[c].pb(mp(a, b));
        }
        solve();
        for (int i = 0; i < N; i++)
            VG[i].clear();
        for (int i = 1; i <= n; i++)
        {
            for (auto temp : G[i])
            {
                int v1 = temp.X, v2 = temp.Y;
                if (belong[v1] == belong[i])
                    v1 = -1;
                else
                    v1 = belong[v1], deg[v1]++;
                if (belong[v2] == belong[i])
                    v2 = -1;
                else
                    v2 = belong[v2], deg[v2]++;
                VG[belong[i]].pb(mp(v1, v2));
            }
        }
        clr(has, 0);
        for (int i = 0; i < k; i++)
        {
            int x;
            cin >> x;
            has[belong[x]] = true;
        }
        init_ans();
        for (int i = 0; i < q; i++)
        {
            int x;
            cin >> x;
            if (has[belong[x]])
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
    }
    return 0;
}
